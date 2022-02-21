/*
 * Solution.cpp
 *
 *  Created on: Feb 10, 2022
 *      Author: ysiyer
 */


#include <iostream>

using namespace std;

class MyLinkedList {
private:
	struct node {
		int val;
		node* next;
		node(): val(0), next(nullptr) {}
		node(int x): val(x), next(nullptr) {}
	};
	node* root;
public:
	MyLinkedList() {
		root = nullptr;
	}

	int get(int index) {
		node* n = root;
		int i = 0;

		while (i < index && n->next != nullptr) {
			i++;
			n = n->next;
		}

		if (i < index || n == nullptr) return -1;
		return n->val;
	}

	void addAtHead(int val) {
		node* n = new node(val);

		n->next = root;
		root = n;
	}

	void addAtTail(int val) {
		node* n = new node(val);
		node* t = root;

		if (root == nullptr) {
			root = n;
			return;
		}

		while (t->next != nullptr) t = t->next;
		t->next = n;
	}

	void addAtIndex(int index, int val) {
		node* n = new node(val);
		node* t = root;
		int  i = 0;

		if (index == 0) {
			n->next = root;
			root = n;
			return;
		}

		while (i < index-1 && t->next != nullptr) {
			i++;
			t = t->next;
		}

		if (i < index-1 || t == nullptr)
			return;

		n->next = t->next;
		t->next = n;
	}

	void deleteAtIndex(int index) {
		int i = 0;
		node* t = root;
		while (i < index-1 && t->next != nullptr) {
			i++;
			t = t->next;
		}

		if (index == 0) {
			node* d = root;
			root = root->next;
			delete d;
			return;
		}

		if (t->next != nullptr) {
			node* d = t->next;
			t->next = t->next->next;
			delete d;
		}
	}
};

int main()
{
	MyLinkedList* l = new MyLinkedList();

	l->addAtHead(1);
	l->addAtTail(3);
	l->addAtIndex(1, 2);
	cout << l->get(1) << endl;
	l->deleteAtIndex(1);
	cout << l->get(1) << endl;
}
