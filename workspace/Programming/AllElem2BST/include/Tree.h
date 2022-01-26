/*
 * Tree.h
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Tree {
public:
	TreeNode *m_root;
	Tree();
	Tree(vector<int> v);
	TreeNode* insert(TreeNode *r, int val);
};

#endif /* TREE_H_ */
