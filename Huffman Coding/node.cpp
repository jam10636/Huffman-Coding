#include"node.h"
char node::getCharacter() const
{
	return char1;
}
int node::getFrequency() const
{
	return  freq;
}
NodeInterface* node::getLeftChild() const
{
	return left;
}
NodeInterface* node::getRightChild() const
{
	return right;
}