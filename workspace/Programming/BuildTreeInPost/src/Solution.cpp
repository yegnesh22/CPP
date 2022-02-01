/*
 * Solution.cpp
 *
 *  Created on: Feb 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.pre) ? "pass" : "fail")

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ti {
	vector<int> in;
	vector<int> po;
	TreeNode* r;
	vector<int> pre;
	vector<int> ao;
};

class Solution {
public:
    virtual TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) = 0;
    vector<int> genV(TreeNode* r);
    void printV(vector<int> v);
};

vector<int> Solution::genV(TreeNode* n)
{
	if (n == nullptr)
		return {};

	vector<int> v;
	vector<int> l;
	vector<int> r;

	v.push_back(n->val);
	l = genV(n->left);
	r = genV(n->right);

	v.insert(v.end(), l.begin(), l.end());
	v.insert(v.end(), r.begin(), r.end());

	return v;
}

void Solution::printV(vector<int> v)
{
	cout << "v --> " << flush;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " " << flush;
	cout << endl;
}

class Basic:public Solution {
private:
	TreeNode* constructTree(vector<int>& po, int& ps, vector<int>& in, int s, int e);
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder);
};

TreeNode* Basic::constructTree(vector<int>& po, int& ps, vector<int>& in, int s, int e)
{
	if (s > e)
		return nullptr;

	TreeNode* n = new TreeNode(po[ps]);
	int i = s;

	while ((i < e) && (in[i] != po[ps])) i++;

#ifdef DEBUG
	cout << s << "," << e << ","<< ps << "," << i << endl;
#endif
	if (i+1 <= e) {
		ps--;
		n->right = constructTree(po, ps, in, i+1, e);
	}
	if (i-1 >= s) {
		ps--;
		n->left = constructTree(po, ps, in, s, i-1);
	}
#ifdef DEBUG
	cout << "Node p: " << n << " created with val: " << n->val << endl;;
	cout << "l:" << n->left << " p: " << n->right << endl;;
#endif

	return n;
}

TreeNode* Basic::buildTree(vector<int>& inorder, vector<int>& postorder)
{
	int start = postorder.size() - 1;
	return constructTree(postorder, start, inorder, 0, inorder.size() - 1);
}

int main()
{
	vector<ti> t = {
#ifndef DEBUG
			{
					.in = {9,3,15,20,7},
					.po = {9,15,7,20,3},
					.pre = {3,9,20,15,7},
			},

			{
					.in = {-1},
					.po = {-1},
					.pre = {-1},
			},
			{
					.in = {},
					.po = {},
					.pre = {},
			},
#endif
			{
					.in = {2,1},
					.po = {2,1},
					.pre = {1,2},
			}
	};
	Solution *s = new Basic();

	for (int i = 0; i < t.size(); i++) {
		t[i].r = s->buildTree(t[i].in, t[i].po);
		t[i].ao = s->genV(t[i].r);
		s->printV(t[i].ao);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
