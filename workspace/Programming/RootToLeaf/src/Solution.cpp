/*
 * Solution.cpp
 *
 *  Created on: Jan 11, 2022
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

vector<int> psums;

class Solution {
public:
	void Traverse(TreeNode* root, int sum) {
        //cout << "sum = " << sum << flush;
        //cout << " val = " << root->val << flush;
        sum = sum << 1 | root->val;
		if (root->right == nullptr && root->left == nullptr) {
            //cout << " pushing - " << sum << "..." << endl;
			psums.push_back(sum);
			return;
		}
		if (root->left != nullptr)
			Traverse(root->left, sum);
		if (root->right != nullptr)
			Traverse(root->right, sum);

		return;
	}

	int sumRootToLeaf(TreeNode* root) {
		int sum = 0;

        Traverse(root, sum);
		for (int i = 0; i < psums.size(); i++)
			sum += psums[i];
        psums.clear();
		return sum;
	}
};
