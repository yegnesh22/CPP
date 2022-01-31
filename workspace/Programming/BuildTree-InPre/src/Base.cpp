/*
 * Base.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#include <Base.h>

vector<int> Solution::buildVector(TreeNode* root)
{
	if (root == nullptr)
		return {};

	vector<int> v;
	vector<int> l = buildVector(root->left);
	vector<int> r = buildVector(root->right);

	v.insert(v.end(), l.begin(), l.end());
	v.insert(v.end(), r.begin(), r.end());
	v.push_back(root->val);

	return v;
}
