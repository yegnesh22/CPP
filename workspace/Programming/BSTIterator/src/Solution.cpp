/*
 * Solution.cpp
 *
 *  Created on: Feb 5, 2022
 *      Author: ysiyer
 */

#include <iostream>
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

class BSTIterator {
private:
	int m_cur;
	vector<TreeNode*> m_tlist;
	void cTList(TreeNode* root);
public:
    BSTIterator(TreeNode* root);
    int next();
    bool hasNext();
};

void BSTIterator::cTList(TreeNode* root)
{
	if (root->left == nullptr && root->right == nullptr) {
		m_tlist.push_back(root);
		return;
	}

	if (root->left != nullptr)
		cTList(root->left);

	m_tlist.push_back(root);

	if (root->right != nullptr)
		cTList(root->right);

	return;
}

BSTIterator::BSTIterator(TreeNode* root)
{
	if (root != nullptr)
		cTList(root);
	m_cur = 0;
}

bool BSTIterator::hasNext()
{
	return m_cur < m_tlist.size();
}

int BSTIterator::next()
{
	TreeNode* c = m_tlist[m_cur];
	m_cur++;
	return c->val;
}

int main()
{
	TreeNode* r = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
	BSTIterator* t = new BSTIterator(r);

	cout << t->next() << endl; // return 3
	cout << t->next()  << endl;// return 7
	cout << t->hasNext() << endl;// return True
	cout << t->next() << endl;// return 9
	cout << t->hasNext() << endl;// return True
	cout << t->next() << endl;// return 15
	cout << t->hasNext() << endl;// return True
	cout << t->next() << endl;// return 20
	cout << t->hasNext() << endl;// return False

	return 0;
}
