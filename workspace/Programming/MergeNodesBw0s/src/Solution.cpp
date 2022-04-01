/*
 * Solution.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
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
	ListNode* mergeNodes(ListNode* head);
};

ListNode* Solution::mergeNodes(ListNode* head)
{
	ListNode* m_root = nullptr;
	ListNode* t = head->next;
	ListNode* t_m = m_root;
	ListNode* p_m;
	int sum = 0;

	while (t != nullptr) {
		if (t->val == 0) {
			t_m = new ListNode(sum);
			if (m_root == nullptr) {
				m_root = t_m;
				p_m = t_m;
			} else {
				p_m->next = t_m;
				p_m = t_m;
			}
			sum = 0;
		} else
			sum += t->val;

		t = t->next;
	}

	return m_root;
}

struct ti {
	ListNode* head;
	ListNode* m;
	vector<int> eo;
	vector<int> ao;
	ti(ListNode* h, vector<int> teo): head(h), eo(teo) {}
};

vector<int> genV(ListNode* h)
{
	ListNode* t = h;
	vector<int> r;

	cout << "v -- " << flush;
	while (t != nullptr) {
		r.push_back(t->val);
		cout << t->val << " " << flush;
		t = t->next;
	}
	cout << endl;

	return r;
}

vector<ti> t = {
		ti(new ListNode(0, new ListNode(3, new ListNode(1, new ListNode(0, new ListNode(4, new ListNode(5, new ListNode(2, new ListNode(0)))))))),
				{4,11}),
		ti(new ListNode(0, new ListNode(1, new ListNode(0, new ListNode(3, new ListNode(0, new ListNode(2, new ListNode(2, new ListNode(0)))))))),
				{1,3,4}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].m = s->mergeNodes(t[i].head);
		t[i].ao = genV(t[i].m);
		assert(t[i].eo == t[i].ao);
		cout << i << " -- pass " << endl;
	}

	return 0;
}
