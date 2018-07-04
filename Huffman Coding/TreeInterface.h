//YOU MAY NOT MODIFY THIS DOCUMENT

#pragma once

#include "NodeInterface.h"

using namespace std;

class TreeInterface {
public:
	TreeInterface() {}
	virtual ~TreeInterface() {}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual NodeInterface * getRootNode() = 0;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(char data) = 0;

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear() = 0;
};
