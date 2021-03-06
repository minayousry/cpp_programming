// BinaryTree_equality_problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;
};

bool CheckNode(Node* node1, Node* node2)
{
	bool result = true;

	if ((node1 == nullptr) && (node2 == nullptr))
	{
		result = true;
	}
	else if ((node1 != nullptr) && (node2 != nullptr))
	{
		if (node1->data == node2->data)
		{
			result &= CheckNode(node1->left, node2->left);
			if (result == true)
			{
				result &= CheckNode(node1->right, node2->right);
			}

		}
		else
		{
			result = false;
		}
	}
	else
	{
		return false;
	}
	return result;

}

bool CheckBinaryTreeEquality(Node* root1, Node* root2)
{
	bool result = true;

	result = CheckNode(root1, root2);

	return result;
}

int main()
{
	static Node node3;
	static Node node2;
	static Node node5;
	static Node node1;
	static Node node4;

	static Node nodec3;
	static Node nodec2;
	static Node nodec5;
	static Node nodec1;
	static Node nodec4;

	node3.data = nodec3.data = 3;
	node2.data = nodec2.data = 2;
	node5.data = nodec5.data = 5;
	node1.data = nodec1.data = 1;
	node4.data = 4;
	nodec4.data = 4;

	node3.left = &node2;
	node3.right = &node5;
	node2.left = &node1;
	node2.right = &node4;


	nodec3.left = &nodec2;
	nodec3.right = &nodec5;
	//nodec2.left = &nodec1;
	nodec2.right = &nodec4;

	cout << CheckBinaryTreeEquality(&node3, &nodec3);
	system("pause");
    return 0;
}

