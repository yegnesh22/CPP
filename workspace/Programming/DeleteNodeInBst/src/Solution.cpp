/*
 * Solution.cpp
 *
 *  Created on: Feb 24, 2022
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

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key);
    void createV(TreeNode* r, vector<int>& v);
};

TreeNode* Solution::deleteNode(TreeNode* root, int key)
{
    if (root == nullptr)
        return root;

	// Special case for root
	if (root->val == key) {
		TreeNode* t = root->right;
		TreeNode* d = root;
        if (t != nullptr) {
		    while (t->left != nullptr) t = t->left;
		    t->left = root->left;
            root = root->right;
        } else {
            root = root->left;
        }
		delete d;
		return root;
	}

	TreeNode* t = root;
	while (t != nullptr) {
		if (t->val > key) {
			if (t->left == nullptr) // key not found
				return root;
			if (t->left->val == key) { // key found
				TreeNode* sl = t->left->left;
				TreeNode* d = t->left;
				t->left = t->left->right;
				while (t->left != nullptr) t = t->left;
				t->left = sl;
				delete d;
				return root;
			}
			t = t->left;
		} else {
			if (t->right == nullptr) // key not found
				return root;
			if (t->right->val == key) { // key found
				TreeNode *sr = t->right->right;
				TreeNode* d = t->right;
				t->right = t->right->left;
				while (t->right != nullptr) t = t->right;
				t->right = sr;
				delete d;
				return root;
			}
			t = t->right;
		}
	}
	return root;
}

void Solution::createV(TreeNode* r, vector<int>& v)
{
	if (r->left != nullptr)
		createV(r->left, v);

	v.push_back(r->val);

	if (r->right != nullptr)
		createV(r->right, v);

	return;
}

struct ti {
	TreeNode* r;
	int k;
	vector<int> eo;
	vector<int> ao;
};

vector<ti> t = {
		{
				.r = new TreeNode(5, new TreeNode(3, new TreeNode(2), new TreeNode(4)), new TreeNode(6, nullptr, new TreeNode(7))),
				.k = 3,
				.eo = {2,4,5,6,7},
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].r = s->deleteNode(t[i].r, t[i].k);
		s->createV(t[i].r, t[i].ao);
		cout << "v -- " << flush;
		for (int j = 0; j < t[i].ao.size(); j++) {
			cout << t[i].ao[j] << " " << flush;
		}
		cout << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
