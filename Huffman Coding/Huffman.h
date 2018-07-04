#pragma once
#include"HuffmanInterface.h"
#include"node.h"
#include"tree.h"
#include<fstream>
#include<algorithm>
#include<queue>
#include<vector>
static struct {
	bool operator()(NodeInterface* a, NodeInterface* b) {
		if (a->getFrequency() == b->getFrequency()) {//if the frequencies are even,
			if (b->getCharacter() == '\0') return false;
			if (a->getCharacter() != '\0') {
				return (int)a->getCharacter() < (int)b->getCharacter();

			}
			return false;
		}
		return a->getFrequency() < b->getFrequency();
	}
} sorter;

class Huffman :public HuffmanInterface
{
public:
	Huffman() {};
	~Huffman()
	{
		clear(root);
	}
	bool createTree(string filename);
	void code(string code,node*x);
	string encodeMessage(string toEncode);
	string decodeMessage(string toDecode);
	TreeInterface * getTree();
	void clear(node*x);
	map<char, string> getEncodings();

	
protected:
	map<char, string>list;
	string name;
	string code1;
	node* root = NULL;
	vector<node*> list1;
	tree* head = NULL;
};