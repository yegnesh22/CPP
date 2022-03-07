/*
 * Solution.cpp
 *
 *  Created on: Mar 7, 2022
 *      Author: ysiyer
 */

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

class Solution {
	bool m_balanced = true;
public:
	int check(TreeNode* n);
	bool isBalanced(TreeNode* root);
};

int Solution::check(TreeNode* n)
{
	if (n == nullptr)
		return 0;

	int slh = 0;
	int srh = 0;

	slh = check(n->left);
	srh = check(n->right);
	if (abs(slh - srh) > 1)
		m_balanced = false;
	return max(slh + 1, srh + 1);
}

bool Solution::isBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;

	if (root->left == nullptr && root->right == nullptr)
		return true;

	int lh = check(root->left);
	int rh = check(root->right);

	return abs(lh - rh) <= 1 && m_balanced;
}

struct ti {
	TreeNode* r;
	bool eo;
	bool ao;
};

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

vector<ti> t = {
		{
				.r = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))),
				.eo = true,
		},
		{
				.r = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), new TreeNode(4)), new TreeNode(3)) , new TreeNode(2)),
				.eo = false,
		},
		{
				.r = new TreeNode(1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr), new TreeNode(2,nullptr, new TreeNode(3, nullptr, new TreeNode(4)))),
				.eo = false,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->isBalanced(t[i].r);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
