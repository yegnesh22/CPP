/*
 * Solution.cpp
 *
 *  Created on: Jan 22, 2022
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
	ListNode* insert(ListNode* head, int val) {
		ListNode* n = new ListNode(val);

		//cout << "Newnode:" << n << endl;
		if (head == nullptr)
			return n;

		ListNode* t = head;
		while (t->next != nullptr)
			t = t->next;

		t->next = n;
		return head;
	}

	vector<int> createV(ListNode* h) {
		vector<int> r;
		while (h) {
			//cout << "Node: " << h << endl;
			r.push_back(h->val);
			h = h->next;
		}
		return r;
	}

	string printV(vector<int> v) {

		for (int i = 0; i < v.size(); i++)
			cout << " " << v[i];

		return " ";
	}

	void cleanup(ListNode* h) {
		ListNode* t = h;
		ListNode* t1 = h;

		while (t) {
			t = t->next;
			delete t1;
			t1 = t;
		}
	}

	ListNode* reverseBetween(ListNode* head, int left, int right) {

		if ((left == right) || head == nullptr || head->next == nullptr)
			return head;

		ListNode* lp;
		ListNode* rn;
		ListNode* l;
		ListNode* r;
		ListNode* t;
		bool allset;
		int count;

		l = lp = r = rn = nullptr;
		t= head;
		allset = false;
		count = 1;

		if (count == left) // first node case
			l = head;

		while (t != nullptr) {
			if ((count + 1) == left) {
				l = t->next;
				lp = t;
			}
			if (count == right) {
				r = t;
				rn = t->next;
			}

			if ((l != nullptr) && (r != nullptr)) {
				allset = true;
				break;
			}

			count++;
			t = t->next;
		}

		//cout << "l:" << l << " r:" << r << endl;
		// Insufficient/Invalid input
		if (allset == false)
			return head;

		// Reverse between l and r
		t = l;
		ListNode* t1 = t->next;
		ListNode* t2 = t1->next;
		while (t != r) {
			t1->next = t;
			t = t1;
			t1 = t2;
			if (t2 != nullptr)
				t2 = t2->next;
		}

		if (lp != nullptr) {
			lp->next = r;
			l->next = rn;
		} else {
			//cout << "Setting head to : " << r << endl;
			l->next = rn;
			return r;
		}

		return head;
	}
};

struct TI {
	vector<int> i;
	vector<int> eo;
	int l;
	int r;
	ListNode* h;
	vector<int> ao;
};

vector<TI> t = {
		{
				.i = {1,2,3,4,5},
				.eo = {1,4,3,2,5},
				.l = 2,
				.r = 4,
		},
		{
				.i = {5},
				.eo = {5},
				.l = 1,
				.r = 1,
		},
		{
				.i = {3,5},
				.eo = {3,5},
				.l = 2,
				.r = 2,
		},
		{
				.i = {3,5},
				.eo = {5,3},
				.l = 1,
				.r = 2,
		}
};

int main()
{
	Solution *s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		// Create the list
		t[i].h = nullptr;
		for (int k = 0; k < t[i].i.size(); k++) {
			t[i].h = s->insert(t[i].h, t[i].i[k]);
		}

		// Reverse the list
		t[i].h = s->reverseBetween(t[i].h, t[i].l, t[i].r);
		t[i].ao = s->createV(t[i].h);

		// Print the result
		cout << "t[" << i << "] -- eo = " << s->printV(t[i].eo)
						<< " ao = " << s->printV(t[i].ao)
						<< " r = " << ((t[i].eo == t[i].ao) ? "pass":"fail")
						<< endl;

		// Cleanup the list
		s->cleanup(t[i].h);
	}

	delete s;
	return 0;
}
