#pragma once
#include"TreeInterface.h"
#include"Node.h"
class tree :public TreeInterface
{
	tree() {};
	~tree() {};
		NodeInterface * getRootNode();
		bool add(char data);
		void clear();
	node* head = NULL;
	
};