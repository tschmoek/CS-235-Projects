#pragma once
#include "BSTInterface.h"
#include "Node.h"

class BST : public BSTInterface
{
private:
	Node* root;

public:
	BST();
	~BST();

	  NodeInterface * getRootNode();
	  bool add(int data);
	  bool recAdd(Node*& cur, int data);
	  bool remove(int data);
	  bool RecRemove(Node*& cur, int data);
	  void clear();
	  int Predicesor(Node*& localroot);
};

//addFunction
//
//is cur NULL ?
//if so add node
//
//is value < currentnode
//recursive call left
//
//is value >  currentNode
//rec right
//recAdd(cur->right, data);
//is equal
//dont do anything
//
//
//removing
//write your own recursive function
//so they give you remove(int data)
//you create
//RecursiveRemove(Node*& cur, data)
//
//is data < curdata
//rec left call
//is data > curdata
//rec righ call
//data == curdata			This means we have found the data we are looking for
//
//0 children
//
//1 child
//
//is it the left or right ?
//we promote that child
//store the location of the
//node* temp = currentnode
//cur = cur->right
//delete temp;
//
//
//2 children
//one step to the left
//all the way to the right
//we are trying to get the last digit
//
//In order Predicesor(Node*& localroot, Node*& temp)
//
//Assume the in order predecesor always has a left child
//temp = temp->left;






