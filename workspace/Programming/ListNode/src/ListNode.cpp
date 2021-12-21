/*
 * ListNode.cpp
 *
 *  Created on: 21-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
 	ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
 	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
	ListNode* initNode(int num) {
		ListNode* prev = nullptr;
		ListNode* res = nullptr;
		int d;

		if (num == 0)
			return new ListNode(0);

		while (num) {
			d = num % 10;
			num = num / 10;
			ListNode* node = new ListNode(d);
			if (prev == nullptr) {
				res = node;
				prev = node;
				continue;
			}
			prev->next = node;
			prev = node;
		}
		return res;
	}

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* result = nullptr;
    	ListNode* prev = nullptr;
    	int s = 0, c = 0;

    	while ((l1 != nullptr) && (l2 != nullptr)) {
    		s = l1->val + l2->val + c;
    		if (s >= 10) {
    			s = s % 10;
    			c = 1;
    		} else {
    			c = 0;
    		}
    		ListNode* newd = new ListNode(s);
    		l1 = l1->next;
    		l2 = l2->next;
    		if (result == nullptr) {
				result = newd;
				prev = newd;
				continue;
    		}
    		prev->next = newd;
    		prev = newd;
    	}

    	ListNode* pptr = l1 ? l1 : (l2 ? l2 : nullptr);
		while (pptr != nullptr) {
			s = pptr->val + c;
			if (s >= 10) {
				s = s % 10;
				c = 1;
			} else {
				c = 0;
			}
			ListNode* newd = new ListNode(s);
			prev->next = newd;
			prev = newd;
			pptr = pptr->next;
		}

		if (c == 1) {
			ListNode* newd = new ListNode(c);
			prev->next = newd;
			prev = newd;
		}

		return result;
    }

    void printList(ListNode* l) {
    	while (l != nullptr) {
    		cout << l->val << " --> " << flush;
    		l = l->next;
    	}
    	cout << endl;
    }
};

void run_test(int n1, int n2)
{
	Solution s;

	ListNode* l1 = s.initNode(n1);
	ListNode* l2 = s.initNode(n2);

	ListNode* res = s.addTwoNumbers(l1, l2);

	s.printList(l1);
	s.printList(l2);
	s.printList(res);
}

int main()
{
	run_test(342, 465);
	run_test(0,0);
	run_test(9999999, 9999);

	return 0;
}


