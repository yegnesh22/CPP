/*
 * Solution.cpp
 *
 *  Created on: Jan 24, 2022
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
public:
	TreeNode* insertNode(TreeNode* root, int val) {
		if (root == nullptr) {
			TreeNode* n = new TreeNode(val);
			return n;
		}

		if (root->val > val)
			root->left = insertNode(root->left, val);
		else
			root->right = insertNode(root->right, val);

		return root;
	}

	vector<int> inorderTraversal(TreeNode* root) {
		/*
		 * Inorder traversal: Left, Root, Right.
		 */
		vector<int> v;
		vector<int> l;
		vector<int> r;

		if (root == nullptr)
			return v;

		l = inorderTraversal(root->left);
		r = inorderTraversal(root->right);

		v.insert(v.end(), l.begin(), l.end());
		v.push_back(root->val);
		v.insert(v.end(), r.begin(), r.end());

		return v;
	}

	vector<int> preorderTraversal(TreeNode* root) {
		/*
		 * Preorder traversal: Root, Left, Right.
		 */
		vector<int> v;
		vector<int> l;
		vector<int> r;

		if (root == nullptr)
			return v;

		l = preorderTraversal(root->left);
		r = preorderTraversal(root->right);

		v.push_back(root->val);
		v.insert(v.end(), l.begin(), l.end());
		v.insert(v.end(), r.begin(), r.end());

		return v;
	}

	vector<int> postorderTraversal(TreeNode* root) {
		/*
		 * Postorder traversal: Left, Right, Root.
		 */
		vector<int> v;
		vector<int> l;
		vector<int> r;

		if (root == nullptr)
			return v;

		l = postorderTraversal(root->left);
		r = postorderTraversal(root->right);

		v.insert(v.end(), l.begin(), l.end());
		v.insert(v.end(), r.begin(), r.end());
		v.push_back(root->val);

		return v;
	}
};

struct ti {
	vector<int> i;
	vector<int> eo;
	vector<int> ao;
	TreeNode* r;
};

vector<ti> t = {
		{
				.i = {1,2,3},
				.eo = {1,3,2},
		},
		{
				.i = {},
				.eo = {},
		},
		{
				.i = {1},
				.eo = {1},
		},
};

int main()
{
	Solution *s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].r = nullptr;
		for (int j = 0; j < t[i].i.size(); j++) {
			t[i].r = s->insertNode(t[i].r, t[i].i[j]);
		}
		t[i].ao = s->inorderTraversal(t[i].r);

		cout << "t[" << i << "] -- r:"
				<<  ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}

	return 0;
}
