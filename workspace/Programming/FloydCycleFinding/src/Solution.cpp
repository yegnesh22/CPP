/*
 * Solution.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

/*
 * 2 pointers - 1 fast 1 slow.
 *
 * fast pointer - moves by 2 steps
 * slow pointer - moves by 1 step
 *
 * If cycle exists - fast will reach slow pointer
 * If cycle does not exist, fast will reach null.
 *
 */


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (slow != nullptr) {
            if (slow == fast) {
                return true;
            }
            if (fast == nullptr || fast->next == nullptr)
                return false;

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};

