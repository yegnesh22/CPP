/*
 * Basic.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#include <Basic.h>

/*
 * Algorithm:
 * Use stack to store the indices of the bars.
 * Iterate the array:
 * While stack is not empty and height[current] > height[st.top()]
 * It means that the stack element can be popped. Pop the top element as top.
 * Find the distance between the current element and the element at top of stack,
 * which is to be filled.
 * distance = current - st.top() - 1
 * Find the bounded height
 * bounded_height = min(height[current],height[st.top()]) - height[top]
 *
 * Add resulting trapped water to answer ans += distance * bounded_height
 * Push current index to top of the stack
 * Move current to the next position
 */

int Basic::trap(vector<int>& height)
{
	int ns = height.size();
	stack<int> stk;
	int total = 0;
	int w, bh;
	int top;

	stk.push(0);
	for (int i = 1; i < ns; i++) {
		if (height[stk.top()] <= height[i]) {
			while (!stk.empty() && (height[stk.top()] <= height[i])) {
				top = stk.top();
				stk.pop();
				if (!stk.empty()) {
					w = i - stk.top() - 1;
					bh = min(height[i], height[stk.top()]) - height[top];
					total += w * bh;
				}
			}
		}

		stk.push(i);
	}

	return total;
}
