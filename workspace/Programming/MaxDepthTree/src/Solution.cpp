/*
 * Solution.cpp
 *
 *  Created on: Feb 14, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ti {
	TreeNode* r;
	int eo;
	int ao;
};

class Solution {
public:
    int maxDepth(TreeNode* root);
};

int Solution::maxDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;

	int rd, ld;

	ld = maxDepth(root->left);
	rd = maxDepth(root->right);

	return max(ld, rd) + 1;
}

vector<ti> t = {
		{
				.r = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))),
				.eo = 3,
		},
		{
				.r = new TreeNode(1, nullptr, new TreeNode(2)),
				.eo = 2,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->maxDepth(t[i].r);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
