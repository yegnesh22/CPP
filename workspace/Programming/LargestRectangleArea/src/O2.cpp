/*
 * O2.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: ysiyer
 */

#include <O2.h>

/*
 * Algorithm
 * In this approach, we maintain a stack. Initially, we push a -1 onto the stack to mark the end.
 * We start with the leftmost bar and keep pushing the current bar's index onto the stack until
 * we get two successive numbers in descending order, i.e. until we get heights[i] < heights[i-1].
 *
 * Now, we start popping the numbers from the stack until we hit a number stack[j] on the stack
 * such that heights[stack[j]] <= heights[i]. Every time we pop, we find out the area of rectangle
 * formed using the current element as the height of the rectangle and the difference between the
 * current element's index pointed to in the original array and the element stack[top-1] - 1 as the
 * width i.e. if we pop an element stack[top] and i is the current index to which we are pointing
 * in the original array, the current area of the rectangle will be considered as:
 * (i - stack[top-1] - 1) x heights[stack[top]].
 *
 * Further, if we reach the end of the array, we pop all the elements of the stack and at every pop,
 * this time we use the following equation to find the area:
 * (heights.length - stack[top-1] - 1) × heights[stack[top]],
 * where stack[top] refers to the element just popped. Thus, we can get the area of the of the
 * largest rectangle by comparing the new area found everytime.
 */

int O2::largestRectangleArea(vector<int>& heights)
{
	int hs = heights.size();
	stack<int> hst;
	int ma = -1;
	int top;
	int ca;
	int w;
	int h;

	hst.push(-1);

	for (int i = 0; i < hs; i++) {
		top = hst.top();
		while ((top != -1) && (heights[top] >= heights[i])) {
			h = heights[top];
			hst.pop();
			top = hst.top();
			w = i - top - 1;
			ca =  h * w ;
			ma = max(ma, ca);
		}
		hst.push(i);
	}

	top = hst.top();
	while(top != -1) {
		h = heights[top];
		hst.pop();
		top = hst.top();
		w  = hs - top - 1;
		ca = w * h;
		ma = max(ma, ca);
	}

	return ma;
}
