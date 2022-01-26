/*
 * Solution.cpp
 *
 *  Created on: Jan 25, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

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
		ListNode* h = head;
		ListNode* t = head;
		ListNode* t1 = head;

		if (h == nullptr || h->next == nullptr)
			return h;

		t = h;
		t1 = t;

		while (t != nullptr) {
			while ((t1->next != nullptr) && (t->val == t1->next->val))
				t1 = t1->next;
			t->next = t1->next;
			t = t->next;
		}

		return head;
	}
};

vector<ti> t = {
		{
				.i = {1,1,2,3,3},
				.eo = {1,2,3},
				.h = nullptr,
		},
		{
				.i = {1,1,2},
				.eo = {1,2},
				.h = nullptr,
		},
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
