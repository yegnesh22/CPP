/*
 * Solution.cpp
 *
 *  Created on: 07-Jan-2022
 *      Author: yegnesh
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    	ListNode* mLH = nullptr;
		ListNode* mLC = nullptr;
    	ListNode* newnode;

    	while ((list1 != nullptr) && (list2 != nullptr)) {
    		if (list1->val < list2->val) {
    			newnode = new ListNode(list1->val);
    			list1 = list1->next;
    		} else {
    			newnode = new ListNode(list2->val);
    			list2 = list2->next;
    		}

    		if (mLH == nullptr)
    			mLH = newnode;
    		if (mLC != nullptr)
    			mLC->next = newnode;
    		mLC = newnode;
    	}

    	while (list1 !=  nullptr) {
    		newnode = new ListNode(list1->val);
    		if (mLH == nullptr)
    			mLH = newnode;
    		if (mLC != nullptr)
    			mLC->next = newnode;
    		mLC = newnode;
    		list1 = list1->next;
    	}
    	while (list2 !=  nullptr) {
    		newnode = new ListNode(list2->val);
    		if (mLH == nullptr)
    			mLH = newnode;
    		if (mLC != nullptr)
    			mLC->next = newnode;
    		mLC = newnode;
    		list2 = list2->next;
    	}
    	return mLH;
    }
};
