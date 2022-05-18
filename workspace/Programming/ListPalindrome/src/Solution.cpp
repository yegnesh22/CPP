/*
 * Solution.cpp
 *
 *  Created on: Apr 19, 2022
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
	bool isPalindrome(ListNode* head) {
		ListNode* half = nullptr;
		ListNode* ht;
		ListNode* ts;
		ListNode* tf;

		// Use fast-slow pointers to find the middle
		ts = head;
		tf = head;
		while (tf != nullptr && tf->next != nullptr) {
			// Create the reverse list while travesing the first half forward
			ListNode* n = new ListNode(ts->val, half);
			half = n;
			tf = tf->next->next;
			ts = ts->next;
		}

		if (tf != nullptr) // Odd number of elements case. Skip middle element comparison
			ts = ts->next;

		// Compare the 2nd half with the reversed first half
		ht = half;
		while (ts != nullptr && ht != nullptr) {
			if (ts->val != ht->val)
				return false;
			ts = ts->next;
			ht = ht->next;
		}

		return (ts == nullptr && ht == nullptr);
	}
};

struct ti {
	ListNode* head;
	bool eo;
	bool ao;
	ti(ListNode* head, bool eo): head(head), eo(eo) {}
};

vector<ti> tests = {
		ti(new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1)))), true),
		ti(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(2, new ListNode(1))))), true),
		ti(new ListNode(1, new ListNode(2)), false),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;

	for (auto t: tests) {
		t.ao = s->isPalindrome(t.head);
		assert(t.ao == t.eo);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
