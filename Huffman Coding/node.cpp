#include"Node.h"
char node::getData()
{
	return alpha;
}
NodeInterface* node:: getLeftChild()
{
	return left;
}
NodeInterface* node:: getRightChild()
{
	return right;
}