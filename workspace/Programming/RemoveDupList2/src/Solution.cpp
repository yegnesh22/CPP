/*
 * Solution.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

/*

Approach 1: Sentinel Head + Predecessor
Sentinel Head
-------------
Let's start from the most challenging situation: the list head is to be removed.
The list head is to be removed. The standard way to handle this use case is to
use the so-called Sentinel Node. Sentinel nodes are widely used for trees and
linked lists as pseudo-heads, pseudo-tails, etc. They are purely functional and
usually don't hold any data. Their primary purpose is to standardize the situation
to avoid edge case handling.

For example, let's use here pseudo-head with zero value to ensure that the situation
"delete the list head" could never happen, and all nodes to delete are "inside" the
list.

Delete Internal Nodes
---------------------
The input list is sorted, and we can determine if a node is a duplicate by comparing
its value to the node after it in the list. Step by step, we could identify the
current sublist of duplicates.

Now it's time to delete it using pointer manipulations. Note that the first node in
the duplicates sublist should be removed as well. That means that we have to track the
predecessor of duplicates sublist, i.e., the last node before the sublist of duplicates.
The sentinel head, the predecessor, and the sublist of duplicates to delete. Having
predecessor, we skip the entire duplicate sublist and make predecessor to point to the
node after the sublist.

*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ti {
	vector<int> i;
	vector<int> eo;
	ListNode* h;
	vector<int> ao;
};

class Solution {
public:
	ListNode* createList(vector<int> V) {
		ListNode* h = nullptr;
		ListNode* t = nullptr;

		for(int i = 0; i < V.size(); i++) {
			ListNode* n = new ListNode(V[i]);
			if (h == nullptr) {
				h = n;
			} else
				t->next = n;
			t = n;
		}

		return h;
	}

	void cleanUp(ListNode* h) {
		ListNode* t = h;
		ListNode* t1 = h;

		while (t != nullptr) {
			t1 = t;
			t = t->next;
			delete t;
		}
	}

	vector<int> createV(ListNode* h) {
		vector<int> v;

		while (h != nullptr) {
			v.push_back(h->val);
			h = h->next;
		}

		return v;
	}

	virtual ListNode* deleteDuplicates(ListNode* head) = 0;
};

class BasicSolution: public Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dh = new ListNode(0,head);
		ListNode* pred = dh;
		bool df = false;

		while (head != nullptr) {
			df = false;
			while (head->next != nullptr && head->val == head->next->val) {
				df = true;
				head = head->next;
			}
			if (df)
				pred->next = head->next;
			else
				pred = pred->next;
			head = head->next;
		}

		return dh->next;
	}
};

vector<ti> t = {
		{
				.i = {1,2,3,3,4,4,5},
				.eo = {1,2,5},
				.h = nullptr,
		},
		{
				.i = {1,1,1,2,3},
				.eo = {2,3},
				.h = nullptr,
		},
		{
				.i = {1,2,2},
				.eo = {1},
				.h = nullptr,
		},
		{
				.i = {1,1,2},
				.eo = {2},
				.h = nullptr,
		}
};

int main()
{
	Solution *s = new BasicSolution();

	for(int i = 0; i < t.size(); i++) {
		t[i].h = s->createList(t[i].i);
		t[i].h = s->deleteDuplicates(t[i].h);
		t[i].ao = s->createV(t[i].h);
		cout << i << " -- " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
