#pragma once
#include"HuffmanInterface.h"
#include"Tree.h"
#include<map>
class huffman : public HuffmanInterface
{
	void createTree(string message);
	string encodeMessage(string toEncode);
	string decodeMessage(string toDecode);
	TreeInterface * getTree();
	vector<string> getEncodings();
	tree x;
};
