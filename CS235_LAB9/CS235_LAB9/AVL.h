
#pragma once
#include "AVLInterface.h"
#include "Node.h"
#include <algorithm>
class AVL :
	public AVLInterface
{
private:
	Node* root;
public:
	AVL();
	~AVL();

	NodeInterface * getRootNode();
	bool find(Node*& cur, int data);
	bool add(int data);
	bool remove(int data);
	bool recAdd(Node*& cur, int data);
    void Predicesor(Node*& cur,Node*& cur2);
	bool RecRemove(Node*& cur, int data);
	void BalanceCheck(Node*& current);
	void rotate_right(Node*& local_root);
	void rotate_left(Node*& local_root);
	void BaltoRight(Node*& cur);
	void BaltoLeft(Node*& cur);
	int getH(Node*& cur);
	void clear();
};





