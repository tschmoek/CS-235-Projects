#pragma once
#include "NodeInterface.h"
class Node : public NodeInterface
{
	friend class BST;
private:
	
	int data;
	Node* left;
	Node* right;

public:
	Node();
	~Node();
	  int getData();
	  NodeInterface * getLeftChild();
	  NodeInterface * getRightChild();

};

