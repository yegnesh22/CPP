/*
 * Solution.cpp
 *
 *  Created on: Jan 24, 2022
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

class Solution {
public:
	ListNode* insert(ListNode*h, int val) {
		ListNode* n = new ListNode(val);
		if (h == nullptr)
			return n;

		ListNode* t = h;

		while(t->next != nullptr)
			t = t->next;

		t->next = n;
		return h;
	}

	vector<int> createV(ListNode* h) {
		vector<int> v;
		while (h!= nullptr) {
			v.push_back(h->val);
			h = h->next;
		}
		return v;
	}

	void printV(vector<int> v) {
		cout << "v --" << flush;
		for (int i = 0; i < v.size(); i++)
			cout << " " << v[i] << flush;
		cout << endl;
	}

    virtual ListNode* rotateRight(ListNode* head, int k) = 0;
};

class BasicSolution: public Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		vector<ListNode*> lookup;
		ListNode* t = head;
		ListNode* tp;
		int count = 0;

		// Empty list or list with 1 element, return as rotation will not
		// make a difference.
		if (t == nullptr || t->next == nullptr || k == 0)
			return t;

		// traverse to the end of the list
		while (t != nullptr) {
			lookup.push_back(t);
			t = t->next;
			count++;
		}

		int index = (count - 1 - (k % count));
		if ((index + 1) != count) {
			lookup[index]->next = nullptr;
			lookup[count - 1]->next = head;
			return lookup[index + 1];
		}
		return lookup[0];
	}
};

struct ti {
	vector<int> i;
	int k;
	vector<int> eo;
	ListNode* h;
	vector<int> ao;
};

vector<ti> t = {
		{
				.i = {1,2,3,4,5},
				.k = 2,
				.eo = {4,5,1,2,3},
		},
		{
				.i = {0,1,2},
				.k = 4,
				.eo = {2,0,1},
		},
		{
				.i = {},
				.k = 10,
				.eo = {},
		},
		{
				.i = {1},
				.k = 5,
				.eo = {1}
		},
		{
				.i = {1,2},
				.k = 2,
				.eo = {1,2}
		},
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i  = 0; i < t.size(); i++) {
		t[i].h = nullptr;
		for (int j = 0; j < t[i].i.size(); j++) {
			t[i].h = s->insert(t[i].h, t[i].i[j]);
		}
		t[i].h = s->rotateRight(t[i].h, t[i].k);
		t[i].ao = s->createV(t[i].h);
		//s->printV(t[i].ao);

		cout << "t[" << i << "] -- r: " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}
}
