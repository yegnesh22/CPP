/*
 * SolutionBase.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#include <SolutionBase.h>

using namespace std;

void Solution::printV(vector<int> V) {
	cout << "V -- " << flush;
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << " " << flush;
	cout << endl;
}

vector<int> Solution::inorderTraverse(TreeNode *root) {
	vector<int> v;

	if (root == nullptr) {
		return {};
	}

	vector<int> l = inorderTraverse(root->left);
	vector<int> r = inorderTraverse(root->right);

	v.insert(v.end(), l.begin(), l.end());
	v.push_back(root->val);
	v.insert(v.end(), r.begin(), r.end());

	return v;
}

