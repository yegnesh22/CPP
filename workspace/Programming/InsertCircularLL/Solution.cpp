#include <iostream>
#include <vector>

using namespace std;

class Node {
	public:
		int val;
		Node* next;

		Node() {}

		Node(int _val) {
			val = _val;
			next = NULL;
		}

		Node(int _val, Node* _next) {
			val = _val;
			next = _next;
		}
};


class Solution {
	public:
		Node* insert(Node* head, int insertVal);
};

Node* Solution::insert(Node* head, int insertVal)
{
	Node* n = new Node(insertVal);

	if (head == nullptr) {
		n->next = n;
		return n;
	}

	Node *tail;
	Node* p = head;
	Node* t = head->next;
	bool found = false;

	do {
		if (p->val <= insertVal && t->val >= insertVal) {
			n->next = t;
			p->next = n;
			return head;
		}

		if (p->val > t->val) {
			if (insertVal > p->val || insertVal < t->val) {
				p->next = n;
				n->next = t;
				return head;
			}
		}
		p = p->next;
		t = t->next;
	} while (p != head);


	p->next = n;
	n->next = t;
	return head;
}

