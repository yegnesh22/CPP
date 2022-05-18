/*
 * Solution.cpp
 *
 *  Created on: Apr 16, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	typedef enum {
		eleft = (1 << 0),
		eright = (1 << 1),
		edown = (eleft | eright),
	} direction;
	vector<int> m_r;
	void Traverse(TreeNode* r, int dist, direction d) {
		if (r == nullptr)
			return;

		if (dist == 0) {
			m_r.push_back(r->val);
			return;
		}

		if (dist < 0)
			return;

		if (d == eleft)
			Traverse(r->left, dist-1, edown);
		if (d == eright)
			Traverse(r->right, dist-1, edown);
		if (d == edown) {
			Traverse(r->left, dist-1, edown);
			Traverse(r->right, dist-1, edown);
		}

		return;
	}

	void findTarget(TreeNode* n, TreeNode* t, bool& found, int& K) {
		if (n == nullptr)
			return;

		if (n->val == t->val) {
			found = true;
			Traverse(n, K, edown);
			return;
		}

		findTarget(n->left, t, found, K);
		if (found) {
			K--;
			Traverse(n, K, eright);
			return;
		}

		findTarget(n->right, t, found, K);
		if (found) {
			K--;
			Traverse(n, K, eleft);
			return;
		}

		return;
	}

	vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
		bool found = false;
		int dist = k;
		findTarget(root, target, found, dist);
		return m_r;
	}
};

struct ti {
	TreeNode* r;
	TreeNode *t;
	int k;
	vector<int> eo;
	vector<int> ao;
	ti(TreeNode* r, TreeNode* t, int k, vector<int> eo): r(r), t(t), k(k), eo(eo) {}
};

vector<ti> tests = {
		ti(new TreeNode(1), new TreeNode(1), 3, {}),
		ti(new TreeNode(3, new TreeNode(5, new TreeNode(6), new TreeNode(2, new TreeNode(7), new TreeNode(4))),
							new TreeNode(1,	new TreeNode(0), new TreeNode(8))),
				new TreeNode(5),
				2, {7, 4, 1}),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto& t: tests) {
		t.ao = s->distanceK(t.r,  t.t, t.k);
		assert(t.ao == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
