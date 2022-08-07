/*
 * Solution.cpp
 *
 *  Created on: Feb 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
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
private:
	int m_level;
	int m_maxWidth;
public:
	void maxWidth(queue<TreeNode*>& wq);
    int widthOfBinaryTree(TreeNode* root);
};

void Solution::maxWidth(queue<TreeNode*>& wq)
{
	queue<TreeNode*> nextLevelWQ;
	TreeNode* tn;
	int width = 1;
	int fWidth = 0;
	int l = m_level;

	cout << "Processing level " << l << endl;
	while (!wq.empty()) {
		tn = wq.front();
		wq.pop();
		if (tn != nullptr) {
			fWidth = width;
			nextLevelWQ.push(tn->left);
			nextLevelWQ.push(tn->right);
		}
		width++;
	}

	m_maxWidth = max(m_maxWidth, fWidth);
	m_level++;
	cout << "isQ empty: " << nextLevelWQ.empty() << endl;
	if (!nextLevelWQ.empty())
		maxWidth(nextLevelWQ);
	cout << "Returning from level " << l << endl;
}

int Solution::widthOfBinaryTree(TreeNode* root)
{
	queue<TreeNode*> wq;

	m_level = 0;
	m_maxWidth = 0;
	wq.push(root);
	maxWidth(wq);

	return m_maxWidth;
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
		}
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

