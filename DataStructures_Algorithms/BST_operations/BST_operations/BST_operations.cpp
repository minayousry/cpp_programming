// BST_operations.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct Node
{
	Node *left;
	Node *right;
	int data;
};

class BST
{
private:
	Node * root;

	Node* searchNode(Node *subtree, int data)
	{
		Node *node_address = nullptr;

		if (subtree != nullptr)
		{
			if (data == subtree->data)
			{
				node_address = subtree;
			}
			else if (data < subtree->data)
			{
				node_address = searchNode(subtree->left, data);
			}
			else
			{
				node_address = searchNode(subtree->right,data);
			}
		}
		return node_address;
	}

	Node * getParentNode(Node *subtree,Node* node)
	{
		Node * parent_node = nullptr;
		Node * looping_node = subtree;

		if ((looping_node->right != node) && (looping_node->left == node))
		{
			parent_node = getParentNode(looping_node->right, node);
			parent_node = getParentNode(looping_node->left, node);
		}
		
		return parent_node;



	}
	void createNewNode(Node** node,int data)
	{
		(*node) = new Node;
		(*node)->data = data;
		(*node)->left = nullptr;
		(*node)->right = nullptr;
	}


	void deleteNodeMemory(Node ** node)
	{
		if (*node != nullptr)
		{
			delete *node;
			*node = nullptr;
		}
	}

	Node * deleteNode(Node* subtree, int data)
	{

		// base case
		if (root == NULL)
			return subtree;

		// If the key to be deleted is 
		// smaller than the root's
		// key, then it lies in left subtree
		if (data < subtree->data)
			subtree->left = deleteNode(subtree->left, data);

		// If the key to be deleted is
		// greater than the root's
		// key, then it lies in right subtree
		else if (data > subtree->data)
			subtree->right = deleteNode(subtree->right, data);

		// if key is same as root's key, then This is the node
		// to be deleted
		else {
			// node with only one child or no child
			if (subtree->left == NULL) {
				struct Node* temp = subtree->right;
				delete subtree;
				return temp;
			}
			else if (root->right == NULL) {
				struct Node* temp = subtree->left;
				delete subtree;
				return temp;
			}

			// node with two children: Get the inorder successor
			// (smallest in the right subtree)
			struct Node* temp = getMinValueNode(subtree->right);

			// Copy the inorder successor's content to this node
			subtree->data = temp->data;

			// Delete the inorder successor
			subtree->right = deleteNode(subtree->right, temp->data);
		}
		return subtree;

	}


	void insertNode(Node* subtree,int data)
	{
		if (subtree != nullptr)
		{
			if (data <= subtree->data)
			{
				if (subtree->left == nullptr)
				{
					//createNewNode(&(subtree->left), data);
					subtree->left = new Node;
					subtree->left->data = data;
					subtree->left->right = nullptr;
					subtree->left->left = nullptr;
				}
				else
				{
					insertNode(subtree->left, data);
				}
			}
			else
			{
				if (subtree->right == nullptr)
				{
					//createNewNode(&(subtree->right), data);
					subtree->right = new Node;
					subtree->right->data = data;
					subtree->right->right = nullptr;
					subtree->right->left = nullptr;
				}
				else
				{
					insertNode(subtree->right, data);
				}
			}
		}
	}

	Node* getMinValueNode(Node* subtree)
	{

		Node* looping_node = subtree;

		while ((looping_node != nullptr) &&(looping_node->left != nullptr))
		{
			looping_node = looping_node->left;
		}

		return looping_node;
	}

	void printInorderValues(Node* subtree)
	{
		Node* looping_node = subtree;

		if (looping_node != nullptr)
		{
			if (looping_node->left != nullptr)
			{
				printInorderValues(looping_node->left);
			}
			cout << looping_node->data << " ";

			if (looping_node->right != nullptr)
			{
				printInorderValues(looping_node->right);
			}
		}

	}

	void printPreorderValues(Node* subtree)
	{
		Node* looping_node = subtree;

		if (looping_node != nullptr)
		{
			cout << looping_node->data << " ";

			if (looping_node->left != nullptr)
			{
				printInorderValues(looping_node->left);
			}

			if (looping_node->right != nullptr)
			{
				printInorderValues(looping_node->right);
			}
		}
	}

	void printPostorderValues(Node* subtree)
	{
		Node* looping_node = subtree;

		if (looping_node != nullptr)
		{
			if (looping_node->left != nullptr)
			{
				printInorderValues(looping_node->left);
			}

			if (looping_node->right != nullptr)
			{
				printInorderValues(looping_node->right);
			}

			cout << looping_node->data << " ";
		}
	}

public:
	BST()
	{
		root = nullptr;
	}
	void insert(int data)
	{
		
		if(root == nullptr)
		{
			createNewNode(&root, data);
		}
		else
		{
			insertNode(root, data);
		}
	}

	Node* search(int data)
	{
		return searchNode(root,data);
	}

	bool removeNode(int data)
	{
		bool result = false;
		Node* found_node;
		deleteNode(root, data);


		return result;
		
	}


	void inOrderPrint()
	{
		printInorderValues(root);
	}

	void preOrderPrint()
	{
		printPreorderValues(root);
	}

	void postOrderPrint()
	{
		printPostorderValues(root);
	}

	int FindLowestAccessor()
	{
		return 0;
	}

	void destroy_tree()
	{

	}

	~BST()
	{
		destroy_tree();
	}

};

int main()
{

	/* Let us create following BST
	50
	/     \
	30     70
	/ \ / \
	20 40 60 80 */
	BST binary_tree;

	binary_tree.insert(50);
	binary_tree.insert(30);
	binary_tree.insert(20);
	binary_tree.insert(40);
	binary_tree.insert(70);
	binary_tree.insert(60);
	binary_tree.insert(80);

	cout << "Inorder traversal of the given tree \n";
	binary_tree.inOrderPrint();

	cout << "\nDelete 20\n";
	binary_tree.removeNode(20);
	cout << "Inorder traversal of the modified tree \n";
	binary_tree.inOrderPrint();

	cout << "\nDelete 30\n";
	binary_tree.removeNode(30);
	cout << "Inorder traversal of the modified tree \n";
	binary_tree.inOrderPrint();

	cout << "\nDelete 50\n";
	binary_tree.removeNode(50);
	cout << "Inorder traversal of the modified tree \n";
	binary_tree.inOrderPrint();

	system("pause");
	return 0;
}


