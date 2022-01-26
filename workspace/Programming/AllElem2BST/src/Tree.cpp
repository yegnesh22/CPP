/*
 * Tree.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#include <Tree.h>

TreeNode* Tree::insert(TreeNode *r, int val) {
	if (r == nullptr) {
		TreeNode *n = new TreeNode(val);
		return n;
	}

	if (r->val > val)
		r->left = insert(r->left, val);

	else
		r->right = insert(r->right, val);

	return r;
}

Tree::Tree(vector<int> v) {
	m_root = nullptr;
	for (int i = 0; i < v.size(); i++) {
		m_root = insert(m_root, v[i]);
	}
}

Tree::Tree() {
	m_root = nullptr;
}
