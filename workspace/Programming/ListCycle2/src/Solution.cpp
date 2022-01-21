/*
 * Solution.cpp
 *
 *  Created on: Jan 19, 2022
 *      Author: ysiyer
 */
#include <iostream>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    	map<ListNode*, int> lookup;
        map<ListNode*, int>::iterator it;
    	ListNode* list = head;
        int i = 0;

        if ((list!= NULL) && (list->next == list))
            return list;

        if (list == NULL)
            return NULL;

    	while(list != NULL) {
    		it = lookup.find(list->next);
    		if (it != lookup.end())
    			return list->next;
            lookup.insert(pair<ListNode*, int>(list, i));
            list = list->next;
            i++;
    	}
    	return NULL;
    }
};
