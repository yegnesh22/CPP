/*
 * Basic.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#include <Basic.h>

TreeNode* BasicSolution::constructTree(vector<int>& po,
										vector<int>& io,
										int& ri, int s, int e)
{
	cout << "Creating " << ri << " node: " << po[ri] << endl;
	TreeNode* root = new TreeNode(po[ri]);
	int i = 0;

	while (po[ri] != io[i])
		i++;


	if (s <= i-1) {
		ri++;
		root->left = constructTree(po, io, ri, s, i-1);
	}

	if (i+1 <= e) {
		ri++;
		root->right = constructTree(po, io, ri, i+1, e);
	}

	return root;
}

TreeNode* BasicSolution::buildTree(vector<int>& preorder,
									vector<int>& inorder)
{
	int end = inorder.size() - 1;
	int start = 0;
	int ri = 0;

	return constructTree(preorder, inorder, ri, start, end);
}
