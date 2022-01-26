/*
 * BasicSolution.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#include <Tree.h>
#include <BasicSolution.h>

TreeNode* BasicSolution::mergeTree(TreeNode *root1, TreeNode *root2) {
	TreeNode *tl;
	TreeNode *tr;
	TreeNode *p;

	if (root1 == nullptr)
		return root2;

	if (root2 == nullptr)
		return root1;

	if (root1->val < root2->val) {
		tl = root2->left;
		p = root2;
		while (tl != nullptr) {
			p = tl;
			if (tl->val < root1->val)
				tl = tl->right;
			else
				tl = tl->left;
		}

		if (p->val < root1->val)
			p->right = root1;
		else
			p->left = root1;
		tr = root2;
		p = root2;
		while (tr != nullptr && root1->right != nullptr) {
			p = tr;
			if (tr->val < root1->right->val)
				tr = tr->right;
			else
				tr = tr->left;
		}
		if (p->val < root1->right->val)
			p->right = root1->right;
		else
			p->left = root1->right;

		root1->right = nullptr;
		return root2;
	} else {
		tl = root1->left;
		p = root1;
		while (tl != nullptr) {
			p = tl;
			if (tl->val < root2->val)
				tl = tl->right;
			else
				tl = tl->left;
		}
		if (p->val < root2->val)
			p->right = root2;
		else
			p->left = root2;
		tr = root1;
		p = root1;
		while (tr != nullptr && root2->right != nullptr) {
			p = tr;
			if (tr->val < root2->right->val)
				tr = tr->right;
			else
				tr = tr->left;
		}
		if (p->val < root2->right->val)
			p->right = root2->right;
		else
			p->left = root2->right;
		root2->right = nullptr;
		return root1;
	}
	return nullptr;
}

vector<int> BasicSolution::getAllElements(TreeNode *root1, TreeNode *root2) {
	TreeNode *nr;

	cout << "Merge the trees and then traverse method" << endl;
	// Merge the trees
	nr = mergeTree(root1, root2);

	return inorderTraverse(nr);
}

