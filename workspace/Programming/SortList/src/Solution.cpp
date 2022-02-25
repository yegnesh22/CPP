/*
 * Solution.cpp
 *
 *  Created on: Feb 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <set>

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
    ListNode* sortList(ListNode* head);
};

ListNode* Solution::sortList(ListNode* head)
{
	ListNode* t = head;
	multiset<int> l;

	while (t != nullptr) {
		l.insert(t->val);
		t = t->next;
	}

	auto it = l.begin();
	t = head;
	while (t != nullptr) {
		t->val = *it;
		it++;
		t = t->next;
	}

	return head;
}

// TODO - Try merge sort
#if 0
ListNode* Solution::sortList(ListNode* head)
{
}
#endif

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	ListNode* h;
	vector<int> eo;
	ListNode* nh;
	vector<int> ao;
};

vector<ti> t = {
		{
				.h = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3)))),
				.eo = {1,2,3,4},
		},
		{
				.h = new ListNode(-1, new ListNode(5, new ListNode(3, new ListNode(4, new ListNode(0))))),
				.eo = {-1,0,3,4,5},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].nh = s->sortList(t[i].h);
		ListNode* trv  = t[i].nh;
		while (trv != nullptr) {
			t[i].ao.push_back(trv->val);
			trv = trv->next;
		}
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
