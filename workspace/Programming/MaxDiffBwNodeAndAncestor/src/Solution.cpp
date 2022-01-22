/*
 * Solution.cpp
 *
 *  Created on: 31-Dec-2021
 *      Author: yegnesh
 */


// Definition for a binary tree node.

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 * Logic:
 * Traverse each node, by recording the max and min values encountered
 * in the path. Update the result (global variable) if its find a value
 * greater than the difference encountered till now.
 * Since result is a global variable, each call will update the final value.
 * curMin and curMax being local variables, individual recursive calls carry
 * their own copy of max and min in their path of ancestors.
 */

class Solution {
public:
	int result = 0;
	void Traverse(TreeNode* n, int curMin, int curMax) {
		if (n == nullptr)
			return;

		int m = max(abs(n->val - curMin), abs(n->val - curMax));
		result = max(result, m);

		curMin = min(curMin, n->val);
		curMax = max(curMax, n->val);

		Traverse(node->left, curMin, curMax);
		Traverse(node->right, curMin, curMax);

		return;
	}

	int maxAncestorDiff(TreeNode* root) {
		result = 0;
		Traverse(root, root->val, root->val);
		return result;
	}
};


