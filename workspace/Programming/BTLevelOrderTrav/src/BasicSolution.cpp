/*
 * BasicSolution.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#include <BasicSolution.h>

vector<vector<int>> BasicSolution::BreadthFirstTraverse(queue<TreeNode*> nl)
{
	vector<vector<int>> nextL;
	vector<vector<int>> l;
	vector<int> thisLevel;
	queue<TreeNode*> next;
	TreeNode* cur;

	while(!nl.empty()) {
		cur = nl.front();
		thisLevel.push_back(cur->val);
		if (cur->left != nullptr)
			next.push(cur->left);
		if (cur->right != nullptr)
			next.push(cur->right);
		nl.pop();
	}

	if (!next.empty())
		nextL = BreadthFirstTraverse(next);

	if (thisLevel.size() > 0)
		l.push_back(thisLevel);

	if (nextL.size() > 0)
		l.insert(l.end(), nextL.begin(), nextL.end());

	return l;
}

vector<vector<int>> BasicSolution::levelOrder(TreeNode* root)
{
	queue<TreeNode*> nl;

	if (root == nullptr)
		return {};

	nl.push(root);
	return BreadthFirstTraverse(nl);
}


