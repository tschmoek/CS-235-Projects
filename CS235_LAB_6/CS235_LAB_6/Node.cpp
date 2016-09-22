	#include "Node.h"


	Node::Node()
	{
		left = NULL;
		right = NULL;
		data = 0;
	}


	Node::~Node()
	{
	}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int Node::getData()
	{
		return data;
	}

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface *Node::getLeftChild()
	{
		return left;
	}

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface *Node::getRightChild()
	{
		return right;
	}
