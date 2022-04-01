/*
 * Solution.cpp
 *
 *  Created on: Mar 23, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct info {
	TreeNode* self;
	TreeNode* parent;
	info(TreeNode* s): self(s), parent(nullptr) {}
};

class Solution {
public:
	TreeNode* createBinaryTree(vector<vector<int>>& descriptions);
	vector<int> TraverseTree(TreeNode* r);
};

vector<int> Solution::TraverseTree(TreeNode* r)
{
	queue<TreeNode*> wq;
	vector<int> res;
	wq.push(r);

#ifdef DEBUG
	cout << "v -- " << endl;
#endif
	while(!wq.empty()) {
		TreeNode* t = wq.front();
		wq.pop();
#ifdef DEBUG
		cout << t->val << " " << flush;
#endif
		res.push_back(t->val);
		if (t->left != nullptr)
			wq.push(t->left);
		if (t->right != nullptr)
			wq.push(t->right);
	}
#ifdef DEBUG
	cout << endl;
#endif

	return res;
}

TreeNode* Solution::createBinaryTree(vector<vector<int>>& descriptions)
{
	int ds = descriptions.size();
	TreeNode* root = nullptr;
	map<int, info*> lkp;

	for (int i = 0; i < ds; i++) {
		if (lkp.find(descriptions[i][0]) == lkp.end()) {
#ifdef DEBUG
			cout << "myself " << descriptions[i][0] << " created!!" << endl;
#endif
			TreeNode* n = new TreeNode(descriptions[i][0]);
			info* nni = new info(n);
			lkp.insert(pair<int, info*>(descriptions[i][0], nni));
		}
		info* ni = lkp[descriptions[i][0]];
		if (lkp.find(descriptions[i][1]) == lkp.end()) {
#ifdef DEBUG
			cout << "my child " << descriptions[i][1] << " created!!" << endl;
#endif
			TreeNode* n = new TreeNode(descriptions[i][1]);
			info* nni = new info(n);
			lkp.insert(pair<int, info*>(descriptions[i][1], nni));
		}
		lkp[descriptions[i][1]]->parent = lkp[descriptions[i][0]]->self;
#ifdef DEBUG
		cout << "setting " << lkp[descriptions[i][1]]->parent->val
				<< " as parent to " << lkp[descriptions[i][1]]->self->val << endl;
#endif
		if (descriptions[i][2] == 1) {
#ifdef DEBUG
			cout << "Adding child " << descriptions[i][1] << " as left!!" << endl;
#endif
			ni->self->left = lkp[descriptions[i][1]]->self;
		} else {
#ifdef DEBUG
			cout << "Adding child " << descriptions[i][1] << " as right!!" << endl;
#endif
			ni->self->right = lkp[descriptions[i][1]]->self;
		}
	}

	for (auto it = lkp.begin(); it != lkp.end(); it++) {
		info* n = it->second;
		if (n->parent == nullptr) {
			root = n->self;
			break;
		}
	}

	return root;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> d;
	vector<int> eo;
	vector<int> ao;
	TreeNode* r;
	ti(vector<vector<int>> td, vector<int> teo): d(td), eo(teo) {}
};

vector<ti> t = {
		ti({{20,15,1},{20,17,0},{50,20,1},{50,80,0},{80,19,1}}, {50,20,80,15,17,19}),
		ti({{1,2,1},{2,3,0},{3,4,1}}, {1,2,3,4}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].r = s->createBinaryTree(t[i].d);
		t[i].ao = s->TraverseTree(t[i].r);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
