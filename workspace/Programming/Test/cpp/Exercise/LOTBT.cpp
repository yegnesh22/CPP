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

int main()
{
	TreeNode* root = new TreeNode(100, new TreeNode(50, new TreeNode(25), new TreeNode(75)), new TreeNode(200, nullptr, new TreeNode(350)));
	queue<TreeNode*> wq;

	wq.push(root);

	while (!wq.empty()) {
		TreeNode* c = wq.front();
		wq.pop();
		cout << c->val << "\t" << flush;
		if (c->l != nullptr)
			wq.push(c->l);
		if (c->r != nullptr)
			wq.push(c->r);
				
	}
	cout << endl;

	return 0;
}
