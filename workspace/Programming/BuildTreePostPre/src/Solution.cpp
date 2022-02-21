/*
 * Solution.cpp
 *
 *  Created on: Feb 21, 2022
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
	TreeNode* m_root;
	vector<int> m_pre;
	vector<int> m_post;
public:
	void printV(vector<int> v);
	void inorder(TreeNode* root, vector<int>& v);
	TreeNode* createTree(int preS, int preE, int poS, int poE);
	TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder);
};

void Solution::printV(vector<int> v)
{
	cout << "v -- " << flush;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " " << flush;
	cout << endl;
}

void Solution::inorder(TreeNode* root, vector<int>& v)
{
	if (root == nullptr)
		return;

	inorder(root->left, v);
	v.push_back(root->val);
	inorder(root->right, v);

	return;
}

TreeNode* Solution::createTree(int preS, int preE, int poS, int poE)
{
	if (preS > preE || poS > poE)
		return nullptr;

	if (preS == preE) {
		return new TreeNode(m_pre[preS]);
	}

	TreeNode* t = new TreeNode(m_pre[preS]);
	int len;
	int i;

	for (i = poS; i < poE; i++) {
		if (m_pre[preS+1] == m_post[i])
			break;
	}
	len = i - poS;

	t->left = createTree(preS+1, preS+len+1, poS, i);
	t->right = createTree(preS+len+2, preE, i+1, poE-1);

	return t;
}

TreeNode* Solution::constructFromPrePost(vector<int>& preorder, vector<int>& postorder)
{
	m_pre = preorder;
	m_post = postorder;
	m_root = createTree(0, preorder.size() - 1, 0, postorder.size() - 1);

	return m_root;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> pre;
	vector<int> post;
	vector<int> eo;
	TreeNode* root;
	vector<int> ao;
};

vector<ti> t = {
		{
				.pre = {1,2,4,5,3,6,7},
				.post = {4,5,2,6,7,3,1},
				.eo = {4,2,5,1,6,3,7},
		},
		{
				.pre = {1},
				.post = {1},
				.eo = {1},
		},
		{
				.pre = {2,1},
				.post = {1,2},
				.eo = {1,2},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].root = s->constructFromPrePost(t[i].pre, t[i].post);
		s->inorder(t[i].root, t[i].ao);
		s->printV(t[i].ao);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
