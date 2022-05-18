/*
 * Solution.cpp
 *
 *  Created on: Apr 17, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		stack<TreeNode*>* next;
		stack<TreeNode*>* cur;
		bool dir = true;

		if (root == nullptr)
			return result;

		next = new stack<TreeNode*>;
		next->push(root);

		TreeNode* n;

		while(!next->empty()) {
			cur = next;
			next = new stack<TreeNode*>;
			vector<int> irV;
			while (!cur->empty()) {
				n = cur->top();
				if (dir == true) {
					irV.push_back(n->val);
					if (n->left != nullptr)
						next->push(n->left);
					if (n->right != nullptr)
						next->push(n->right);
				} else {
					irV.push_back(n->val);
					if (n->right != nullptr)
						next->push(n->right);
					if (n->left != nullptr)
						next->push(n->left);
				}
				cur->pop();
			}
			dir ^= true;
			result.push_back(irV);
		}

		return result;
	}
};

struct ti {
	TreeNode* root;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
	ti(TreeNode* root, vector<vector<int>> eo): root(root), eo(eo) {}
};

vector<ti> tests = {
		ti(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))), {{3}, {20,9}, {15,7}}),
		ti(new TreeNode(1), {{1}}),
		ti(nullptr, {}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		t.ao = s->zigzagLevelOrder(t.root);
		assert(t.eo == t.ao);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
