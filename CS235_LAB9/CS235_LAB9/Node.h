#pragma once
#include "NodeInterface.h"
class Node : public NodeInterface
{
	friend class AVL;
private:

	int data;
	int height;
	Node* left;
	Node* right;

public:
	  Node();
	  ~Node();

	  int getData();
	  NodeInterface * getLeftChild();
	  NodeInterface * getRightChild();
	  int getHeight();
	  
};

