/*
 * Solution.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
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

class Solution {
public:
	void Traverse(TreeNode* n, int& sum);
    TreeNode* convertBST(TreeNode* root);
};

void Solution::Traverse(TreeNode* n, int& sum)
{
	if (n == nullptr)
		return;

	Traverse(n->right, sum);
	//cout << n->val << " rsum:" << sum << flush;
	n->val += sum;
	//cout << " modified to " << n->val << flush;
	sum = n->val;
	//cout << " updated sum to " << sum << endl;
	Traverse(n->left, sum);
}

TreeNode* Solution::convertBST(TreeNode* root)
{
	int sum = 0;
	Traverse(root, sum);
	return root;
}

void getV(TreeNode* n, vector<int>& r)
{
	if (n == nullptr)
		return;

	getV(n->left, r);
	cout << n->val << " " << flush;
	r.push_back(n->val);
	getV(n->right, r);
}

struct ti {
	TreeNode* r;
	vector<int> eo;
	vector<int> ao;
	ti(TreeNode* r, vector<int> eo): r(r), eo(eo) {}
};

vector<ti> tests = {
	ti(new TreeNode(4,
		new TreeNode(1, new TreeNode(0), new TreeNode(2, nullptr, new TreeNode(3))),
		new TreeNode(6, new TreeNode(5), new TreeNode(7, nullptr, new TreeNode(8)))),
		{36, 36, 35, 33, 30, 26, 21, 15, 8}),
	ti(new TreeNode(0,
		nullptr,
		new TreeNode(1)),
		{1,1}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		s->convertBST(t.r);
		getV(t.r, t.ao);
		assert(t.ao == t.eo);
		cout << endl;
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
