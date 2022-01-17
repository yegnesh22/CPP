/*
 * Solution.cpp
 *
 *  Created on: Jan 12, 2022
 *      Author: ysiyer
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* result = head;
		ListNode* node = head;
		ListNode* prev = node;
		ListNode* r = node;

		// Empty list
		if (head == nullptr)
			return head;

		while (n > 0) {
			node = node->next;
			n--;
		}

		while (node != nullptr) {
			prev = r;
			node = node->next;
			r = r->next;
		}

		prev->next = r->next;
		if (head == r)
			result = head->next;

		delete r;
		return result;
	}
};
