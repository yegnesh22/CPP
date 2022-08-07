#include <bits/stdc++.h>

using namespace std;

struct Node {
	int val;
	Node* next;
	Node(): val(0), next(nullptr) {}
	Node(int val): val(val), next(nullptr) {}
	Node(int val, Node* next): val(val), next(next) {}
};

int main()
{
	Node* head1 = new Node(4, new Node(8, new Node(15, new Node(19))));
	Node* head2 = new Node(7, new Node(9, new Node(10, new Node(16))));
	Node* t = nullptr;
	Node* h = nullptr;
	Node* c;
	
	while (head1 != nullptr && head2 != nullptr) {
		if (head1->val < head2->val) {
			c = head1;
			head1 = head1->next;
		} else {
			c = head2;
			head2 = head2->next;
		}
		if (h == nullptr) {
			h = c;
			t = c;
		} else {
			t->next = c;
			t = c;
		}
	}

	if (head1 != nullptr)
		t->next = head1;
	else
		t->next = head2;

	head1 = h;

	t = head1;
	while (t != nullptr) {
		cout << t->val << "\t" << flush;
		t = t->next;
	}
	cout << endl;

	return 0;
}
