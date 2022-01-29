/*
 * Solution.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :
		val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
		val(x), left(left), right(right) {}
};

struct ti {
	TreeNode* root;
	vector<int> eo;
	vector<int> ao;
};

class Solution {
public:
	vector<int> m_r;
	vector<int> m_m;
	vector<int> m_se;
	void printR(vector<int>);
	void inorderTraversal(TreeNode* r, vector<int>&);
	virtual void recoverTree(TreeNode* root) = 0;
};

class Basic : public Solution {
public:
	void findSwappedElems(void);
	void recoverTree(TreeNode* root);
};

void Solution::inorderTraversal(TreeNode* r, vector<int>& v)
{
	if (r == nullptr)
		return;

	if (m_se.size() != 0) {
		if (m_se[0] == r->val)
			r->val = m_se[1];
		else if (m_se[1] == r->val)
			r->val = m_se[0];
	}

	inorderTraversal(r->left, v);
	v.push_back(r->val);
	inorderTraversal(r->right, v);

	return;
}

void Solution::printR(vector<int> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "," << flush;
	cout << "}" << endl;
}

void Basic::findSwappedElems(void)
{
	bool swapfo = false;
	int x, y;

	for (int i = 0; i < m_r.size() - 1; i++) {
		if (m_r[i] > m_r[i + 1]) {
			y = m_r[i + 1];
			if (!swapfo) {
				x = m_r[i];
				swapfo = true;
			} else
				break;
		}
	}

	m_se.push_back(x);
	m_se.push_back(y);
	return;
}

void Basic::recoverTree(TreeNode* root)
{
	inorderTraversal(root, m_r);
	printR(m_r);
	findSwappedElems();
	inorderTraversal(root, m_m);
	printR(m_m);
	return;
}


/*
 *
 * Algorithm:
 * Construct inorder traversal of the tree. It should be an almost
 * sorted list where only two elements are swapped.
 * Identify two swapped elements x and y in an almost sorted array
 * in linear time.
 * Traverse the tree again. Change value x to y and value y to x.
 *
 */

vector<ti> t = {
		{
				.root = new TreeNode(3,new TreeNode(1),new TreeNode(4,new TreeNode(2),nullptr)),
				.eo = {1,2,3,4},
		},
		{
				.root = new TreeNode(1, new TreeNode(3,nullptr,new TreeNode(2)),nullptr),
				.eo = {1,2,3},
		}
};

int main()
{
	Solution *s = new Basic();

	for (int i = 0; i < t.size(); i++) {
		s->recoverTree(t[i].root);
		cout << i << " -- r: " << ((t[i].eo == s->m_m) ? "pass" : "fail") << endl;
		s->m_r.clear();
		s->m_m.clear();
		s->m_se.clear();
	}

	return 0;
}
