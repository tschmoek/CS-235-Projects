	#include "BST.h"


	BST::BST()
	{
		root = NULL;
	}


	BST::~BST()
	{
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode()
	{
		return root;
	}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data)
	{
		recAdd(root, data);
		return true;
	}
	bool BST::recAdd(Node*& cur, int data)
	{
		if (cur == NULL)
		{
			cur = new Node;
			cur->data = data;
			return true;
		}
		else if (data < cur->data)
			recAdd(cur->left, data);
		else if (data > cur->data)
			recAdd(cur->right, data);

        return false;
	}
	int BST::Predicesor(Node*& cur)
	{
		Node* temp = NULL;
		if (cur->right != NULL)
        {
            return Predicesor(cur->right);
        }
		else
        {
            temp = cur->left;
            int data = cur->data;
			delete cur;
            cur = temp;
            return data;
        }
	}
	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data)
	{
		RecRemove(root, data);
		return true;
	}
	bool BST::RecRemove(Node*& cur, int data)
	{
		Node* temp = NULL;
		if (cur == NULL)
		{
			return false;
		}
		if (data < cur->data)
		{
			return RecRemove(cur->left, data);
		}
		else if (data > cur->data)
		{
			return RecRemove(cur->right, data);
		}
		else
		{
			if (cur->left == NULL)
			{
				temp = cur;
				cur = cur->right;
				delete temp;
				return true;
			}
			else if (cur->right == NULL)
			{
				temp = cur;
				cur = cur->left;
				delete temp;
				return true;
			}
			else
			{
				cur->data = Predicesor(cur->left);
				return true;
				//recRemove(cur->left,cur->data);
			}
			
		}

	}
	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear()
	{
		while (root != NULL)
		{
			remove(root->data);
		}
		
	}
