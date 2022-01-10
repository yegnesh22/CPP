/*
 * Solution.cpp
 *
 *  Created on: Jan 9, 2022
 *      Author: ysiyer
 */

#include <algorithm>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	ListNode* curNode = nullptr;
    	ListNode* result = nullptr;
    	vector<int> newL;

    	for (size_t i = 0; i < lists.size(); i++) {
    		ListNode* ptr = lists[i];
    		while(ptr != nullptr) {
    			newL.push_back(ptr->val);
    			ptr = ptr->next;
    		}
    	}
    	sort(newL.begin(), newL.end());

    	for (auto it = newL.begin(); it != newL.end(); it++) {
    		ListNode* newNode = new ListNode(*it);
    		if (curNode != nullptr)
    			curNode->next = newNode;
    		curNode = newNode;
    		if (result == nullptr)
    			result = curNode;
    	}

    	return result;
    }
};
