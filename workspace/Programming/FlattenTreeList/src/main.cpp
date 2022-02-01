/*
 * main.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")

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
    void flatten(TreeNode* root);
    vector<int> traverseList(TreeNode* t);
};

void Solution::flatten(TreeNode* c)
{
	if (c == nullptr)
		return;

	TreeNode* n =  c->right;
	if (c->left != nullptr)
		flatten(c->left);

	c->right = c->left;
	c->left = nullptr;

	TreeNode* t = c;
	while(t->right != nullptr)
		t = t->right;

	t->right = n;
	if (n != nullptr) {
		flatten(n);
	}
}

vector<int> Solution::traverseList(TreeNode* t)
{
	vector<int> v;

	cout << "{" << flush;
	while (t != nullptr) {
		cout << " " << t->val << flush;
		v.push_back(t->val);
		t = t->right;
	}
	cout << "}" << endl;

	return v;
}

struct ti {
	TreeNode* r;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.r = new TreeNode(1,
						new TreeNode(2, new TreeNode(3), new TreeNode(4)),
						new TreeNode(5, nullptr, new TreeNode(6))),
						.eo = {1,2,3,4,5,6},
		},
		{
				.r = nullptr,
				.eo = {},
		},
		{
				.r  = new TreeNode(0),
				.eo = {0},
		}
};

int main()
{
	for (int i = 0; i < t.size(); i++) {
		Solution *s = new Solution();
		s->flatten(t[i].r);
		t[i].ao = s->traverseList(t[i].r);
		cout << i << " -- " << check_result(t[i]) << endl;
		delete s;
	}
	return 0;
}
