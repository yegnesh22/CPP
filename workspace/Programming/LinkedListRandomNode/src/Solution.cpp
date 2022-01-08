/*
 * Solution.cpp
 *
 *  Created on: 07-Jan-2022
 *      Author: yegnesh
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
	vector<int> mList;
	size_t mListSize;

    Solution(ListNode* head) {
    	ListNode* node = head;

    	while (node !=  nullptr) {
    		mList.push_back(node->val);
    		node = node->next;
    	}
    	mListSize = mList.size();
    }

    int getRandom() {
    	int index = rand() % mListSize;
    	return mList[index];
    }
};


int main()
{
	Solution* obj = new Solution(head);

	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	cout << obj->getRandom() << endl;
	return 0;
}


