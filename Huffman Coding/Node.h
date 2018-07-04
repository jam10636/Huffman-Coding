#pragma once
#include"NodeInterface.h"
class node :public NodeInterface
{
	friend class tree;
public:
	node() {
		left = NULL;
		right = NULL;
		data1 = 0;
	}
	char getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
protected:
	node*left;
	node*right;
	int data1;
	char alpha;
};
