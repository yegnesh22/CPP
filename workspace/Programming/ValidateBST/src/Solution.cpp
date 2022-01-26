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
	bool checkSubtree(TreeNode* n, TreeNode* l, TreeNode* h) {
		if (n == nullptr)
			return true;

		if ((l != nullptr && n->val <= l->val) ||
				(h != nullptr && n->val >= h->val))
				return false;

		return (checkSubtree(n->right, n, h) && checkSubtree(n->left, l, n));
	}

    bool isValidBST(TreeNode* root) {
    	return checkSubtree(root, nullptr, nullptr);
    }
};


int main()
{
	return 0;
}
