#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* l;
	TreeNode* r;
	TreeNode(): val(0), l(nullptr), r(nullptr) {}
	TreeNode(int val): val(val), l(nullptr), r(nullptr) {}
	TreeNode(int val, TreeNode* l, TreeNode* r): val(val), l(l), r(r) {}
};

bool isBSTrec(TreeNode* n, int min, int max) {
	if (n == nullptr)
		return true;

	if (n->val < min || n->val > max)
		return false;
	return isBSTrec(n->l, min, n->val) && isBSTrec(n->r, n->val, max);
}

bool isBST(TreeNode* root) {
	return isBSTrec(root, INT_MIN, INT_MAX);
}

int main()
{
	TreeNode* t1 = new TreeNode(100, new TreeNode(50, new TreeNode(25), new TreeNode(75)), new TreeNode(200, new TreeNode(125), new TreeNode(350)));
	TreeNode* t2 = new TreeNode(100, new TreeNode(50, new TreeNode(25), new TreeNode(75)), new TreeNode(200, new TreeNode(90), new TreeNode(350)));

	cout << "t1:" << (isBST(t1) ? "true" : "false") << endl;
	cout << "t2:" << (isBST(t2) ? "true" : "false") << endl;
}

