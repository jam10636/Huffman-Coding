#pragma once
#include"NodeInterface.h"
class node: public NodeInterface
{
	friend class tree;
	friend class Huffman;
public:
	node()
	{
		left = NULL;
		char1 = 0;//maybe '\0'
		right = NULL;
	}
	~node() {};
	char getCharacter() const;
	int getFrequency() const;
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
protected:
	node* left;
	node*right;
	char char1;
	int freq;
};