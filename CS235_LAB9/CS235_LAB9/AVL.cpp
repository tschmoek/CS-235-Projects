    #include "AVL.h"
	AVL::AVL()
	{
		root = NULL;
	}
	AVL::~AVL()
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
	NodeInterface * AVL::getRootNode()
	{
		return root;
	}
	/*
	* Attempts to add the given int to the AVL tree
	* Rebalances the tree if data is successfully added
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/

	bool AVL::add(int data)
	{
		bool added;
		if (find(root, data))
		{
			return false;
		}
		added = recAdd(root, data);
		if (added)
		{
			return true;
		}
		return false;
	}
	bool AVL::recAdd(Node*& cur, int data)
	{
		bool check = true;
		if (cur == NULL)
		{
			cur = new Node;
			cur->data = data;
			check = true;
		}
		else if (data < cur->data)
			recAdd(cur->left, data);
		else if (data > cur->data)
			recAdd(cur->right, data);

		BalanceCheck(cur);

		return check;
	}
    void AVL::Predicesor(Node*& cur,Node*& cur2)
	{
        if (cur2->right != NULL )
        {
            Predicesor(cur, cur2->right);
        }
        else
        {
            cur->data = cur2->data;
            Node* temp = cur2;
            cur2 = cur2->left;
            delete temp;
            temp = NULL;

        }
        if (cur2 != NULL)
            BalanceCheck(cur2);
	}

	/*
	* Attempts to remove the given int from the AVL tree
	* Rebalances the tree if data is successfully removed
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool AVL::remove(int data)
	{
		if (!find(root, data))
		{
			return false;
		}
        RecRemove(root, data);
        return true;
	}
	bool AVL::RecRemove(Node*& cur, int data)
	{
		bool check = true;
		Node* temp = NULL;
		if (cur == NULL)
		{
			return false;
		}
		if (data < cur->data)
		{
			RecRemove(cur->left, data);
		}
		else if (data > cur->data)
		{
			RecRemove(cur->right, data);
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
                Predicesor(cur,cur->left);
                BalanceCheck(cur);
				return check;
			}
		}

        BalanceCheck(cur);
		return check;
	}
	void AVL::BalanceCheck(Node*& cur)
	{
		if ((getH(cur->left) - getH(cur->right)) > 1)
		{
			BaltoRight(cur);
		}
		if ((getH(cur->right) - getH(cur->left)) > 1)
		{
			BaltoLeft(cur);
		}
		
	}
	void AVL::BaltoRight(Node*& cur)
	{

        if(getH(cur->left->right) > getH(cur->left->left))
        {
            rotate_left(cur->left);
            rotate_right(cur);
        }
        else
            rotate_right(cur);

	}
	void AVL::BaltoLeft(Node*& cur)
	{
        if (getH(cur->right->left) > getH(cur->right->right))
        {
            rotate_right(cur->right);
            rotate_left(cur);
        }
        else
            rotate_left(cur);

	}
	void AVL::rotate_right(Node*& local_root)
	{
		Node* temp = local_root->left;
		local_root->left = temp->right;
		temp->right = local_root;
		local_root = temp;
	}
	void AVL::rotate_left(Node*& local_root)
	{
		Node* temp = local_root->right;
		local_root->right = temp->left;
		temp->left = local_root;
		local_root = temp;
	}
	int AVL::getH(Node*& cur)
	{
		if (cur != NULL)
        {
            return max(getH(cur->left), getH(cur->right)) + 1;
		}
		else
            return 0;
	}
	void AVL::clear()
	{
		while (root != NULL)
		{
			remove(root->data);
		}
	}
	bool AVL::find(Node*& cur, int data)
	{
			bool found;
            if (cur == NULL)
            {
				found = false;
			}
            else if (cur->data == data)
            {
				found = true;
			}
            else if (data > cur->data)
            {
              found = find(cur->right,data);
            }
            else
               found = find(cur->left,data);


			return found;
	}
