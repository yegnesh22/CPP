/*
 * LinkedListMiddle.cpp
 *
 *  Created on: 28-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>

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
    ListNode* middleNode(ListNode* head) {
    	ListNode* it = head->next;
    	ListNode* mid = head;
    	int i = 2, m = 1;

    	if (it == nullptr)
    		return head;

    	while (it->next != nullptr) {
    		if ((i & 1) == 0) {
    			m++;
    			mid = mid->next;
    		}
    		it = it->next;
    		i++;
    	}

    	cout << m << " " << i << endl;
    	if (m == (i / 2))
    		mid = mid->next;
    	return mid;
    }

    ListNode* insert(ListNode* head, int val) {
    	ListNode* it = head;
    	ListNode* n = new ListNode(val);
    	if (head == nullptr)
    		return n;

    	while(it->next != nullptr)
    		it = it->next;

    	it->next = n;

    	return head;
    }
};

ListNode* l = nullptr;

int main()
{
	ListNode* m;
	Solution s;

	l = s.insert(l, 1); // 0
	//l = s.insert(l, 2); // 1
	//l = s.insert(l, 3); // 2
	//l = s.insert(l, 4); // 3
	//l = s.insert(l, 5); // 4
	//l = s.insert(l, 6); // 5

	m = s.middleNode(l);
	cout << m->val << endl;

	return 0;
}
