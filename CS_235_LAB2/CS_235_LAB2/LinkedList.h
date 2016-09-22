 #pragma once
#include "LinkedListInterface.h"

#include <iostream>
#include <stdexcept>

template<typename T>

class LinkedList : public LinkedListInterface < T >
{
private:

	struct Node {
		T item;
		Node* next;
	};
	Node* head = NULL;
	int count = 0;

public:
	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{
		clear();
	}
	bool find(T value)
	{
		Node* temp = NULL;
			temp = head;
			while (temp != NULL)
			{
				if (temp->item == value)
				{
					return true;
				}
				temp = temp->next;
			}
		return false;
	}
	/*
	insertHead

	A node with the given value should be inserted at the beginning of the list.

	Do not allow duplicate values in the list.
	*/
	void insertHead(T value)
	{
		if (find(value))
		{
			return;
		}
		
		Node* temp = NULL;
		if (head == NULL)
		{
			head = new Node;
			count++;
			head->item = value;
			head->next = NULL;
		}
		else
		{
			temp = new Node;
			count++;
			temp->next = head;
			temp->item = value;
			head = temp;
		}
	}

	/*
	insertTail

	A node with the given value should be inserted at the end of the list.

	Do not allow duplicate values in the list.
	*/
	void insertTail(T value)
	{
		Node* temp = NULL;
		Node* temp2 = NULL;
		if (head == NULL)
		{
			insertHead(value);
		}
		else
		{
			if (find(value))
				return;

				temp = head;
				while (temp != NULL)
				{
					temp2 = temp;
					temp = temp->next;
				}
				temp = new Node;
				count++;
				temp->item = value;
				temp->next = NULL;
				temp2->next = temp;
		}
	}

	/*
	insertAfter

	A node with the given value should be inserted immediately after the
	node whose value is equal to insertionNode.

	A node should only be added if the node whose value is equal to
	insertionNode is in the list. Do not allow duplicate values in the list.
	*/
	void insertAfter(T value, T insertionNode)
	{
		Node* temp = NULL;
		Node* temp2 = NULL;
		if (value != insertionNode)
		{
			if (find(insertionNode) && !find(value))
			{
				temp = head;
				while (temp != NULL)
				{
					if (temp->item == insertionNode)
					{
						temp2 = temp->next;
						temp->next = new Node;
						count++;
						temp->next->item = value;
						temp->next->next = temp2;
						break;
					}
					temp = temp->next;
				}
			}
		}
	}

	/*
	remove

	The node with the given value should be removed from the list.

	The list may or may not include a node with the given value.
	*/
	void remove(T value)
	{
		Node* temp = NULL;
		Node* temp2 = NULL;
		if (head != NULL && find(value))
		{
			temp = head;
			if (temp->item == value)
			{
				head = temp->next;
				delete temp;
				count--;
				return;
			}
			else
			{
				while (temp->next->item != value)
				{
					temp = temp->next;
				}
				temp2 = temp->next;
				temp->next = temp->next->next;
				delete temp2;
				count--;
			}
		
		}

	}

	/*
	clear

	Remove all nodes from the list.
	*/
	void clear()
	{
		Node* temp = NULL;
		while (head != NULL)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		if (head != NULL)
		{
			delete head;
		}
		count = 0;
	}

	/*
	at

	Returns the value of the node at the given index. The list begins at
	index 0.

	If the given index is out of range of the list, throw an out of range exception.
	*/
	T at(int index)
	{
		Node* temp = NULL;
		int i = 0;
		int count = size();
		if (index < 0 || index >= count || head == NULL)
		{
			throw out_of_range("OUT OF RANGE ERROR");
		}
		temp = head;
		while (temp != NULL && i < count)
		{
			if (index == i)
			{
				return temp->item;
			}
			i++;
			temp = temp->next;
		}
		return temp->item;
	}

	/*
	size

	Returns the number of nodes in the list.
	*/
	int size()
	{
		return count;
	}
};


