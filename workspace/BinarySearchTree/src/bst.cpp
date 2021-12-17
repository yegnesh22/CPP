/*
 * bst.cpp
 *
 *  Created on: 16-Dec-2021
 *      Author: yegnesh
 */


#include <iostream>

using namespace std;

#define ARR_SIZE(x) ((sizeof(x) / sizeof(x[0])))

struct node;
struct node {
	struct node *right;
	struct node *left;
	int item;
};

typedef struct node Node;

Node* Insert(Node *root, int data)
{
	if (root == NULL) {
		root = new Node();
		root->left = NULL;
		root->right = NULL;
		root->item = data;
		return root;
	}

	if (data < root->item) {
		root->left = Insert(root->left, data);
	} else {
		root->right = Insert(root->right, data);
	}

	return root;
}

void Inorder(Node *root)
{
	if (root == NULL)
		return;

	Inorder(root->left);
	cout << root->item << "  " << flush;
	Inorder(root->right);
}

int arr[] = {25, 15, 10, 4, 12, 22, 18, 24, 50, 35, 31, 44, 70, 66, 90};

int main()
{
	Node *root = NULL;

	for (int i = 0; i < ARR_SIZE(arr); i++) {
		root = Insert(root, arr[i]);
	}

	Inorder(root);
}
