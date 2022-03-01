/*
 * Solution.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

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
    int widthOfBinaryTree(TreeNode* root);
};

int Solution::widthOfBinaryTree(TreeNode* root)
{
	queue<pair<TreeNode*, long long int>> wq;
	pair<TreeNode*, long long int> p;
   	long long int start;
	long long int end;
	long long int id;
	int maxWidth = 0;
	int cLnumE;

	wq.push({root, 1});

	while (!wq.empty()) {
		cLnumE = wq.size();

		start = wq.front().second;
		end = wq.back().second;

        if (end - start + 1 > maxWidth)
		    maxWidth = end - start + 1;

		for (int i = 0; i < cLnumE; i++) {
			p = wq.front();
			id = p.second - start;
			wq.pop();

			if (p.first->left != nullptr)
				wq.push({p.first->left, (2 * id)});

			if (p.first->right != nullptr)
				wq.push({p.first->right, (2 * id + 1)});

		}
	}

	return maxWidth;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	TreeNode* r;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.r = new TreeNode(1, new TreeNode(3, new TreeNode(5), new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(9))),
				.eo = 4,
		},
		{
				.r = new TreeNode(1, new TreeNode(3, new TreeNode(5), new TreeNode(3)), nullptr),
				.eo = 2,
		},
		{
				.r = new TreeNode(1, new TreeNode(3, new TreeNode(5, new TreeNode(6), nullptr), nullptr), new TreeNode(2, nullptr, new TreeNode(9, nullptr, new TreeNode(7)))),
				.eo = 8,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->widthOfBinaryTree(t[i].r);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
