/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
	void connectNodes(Node* t);
    Node* connect(Node* root);
};

Node* Solution::connect(Node* root)
{
	if (root != nullptr) {
		root->next =  nullptr;
		connectNodes(root);
	}

	return root;
}

void Solution::connectNodes(Node* t)
{
    Node* sb;
    Node* c;

    if (t == nullptr)
        return;

	if (t->left != nullptr) { // Populate the left's next
		if (t->right != nullptr) // If immediate right is not null
			t->left->next = t->right;
		else {
			sb = nullptr;
			c = t->next;
			while (c != nullptr && sb == nullptr) {
				if (c->left != nullptr)
					sb = c->left;
				else if (c->right != nullptr)
					sb = c->right;
				c = c->next;
			}
			t->left->next = sb;
		}
	}

	if (t->right != nullptr) { // Populate the right's next
		sb = nullptr;
		c = t->next;
		while (c != nullptr && sb == nullptr) {
			if (c->left != nullptr)
				sb = c->left;
			else if (c->right != nullptr)
				sb = c->right;
			c = c->next;
		}
		t->right->next = sb;
	}

	// First traverse right as we need the right pointers to be
	// populated to find the cousins and siblings correctly
    connectNodes(t->right);
	connectNodes(t->left);

	return;
}
