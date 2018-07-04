#pragma once
#include"TreeInterface.h"
#include"node.h"
class tree :public TreeInterface
{
public:
	NodeInterface * getRootNode() const;
	tree(node* x)
	{
		head = x;
	}
protected:
	node* head;
};