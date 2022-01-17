/*
 * Solution.cpp
 *
 *  Created on: Jan 11, 2022
 *      Author: ysiyer
 */


/*  Approach 2: Repeated Exponential Searches - Intuition

    Linear Search is too slow because at each step, we only subtract
    one copy of the divisor from the dividend. A better way would be
    to try and subtract multiple copies of the divisor each time.
    One way of quickly increasing numbers, without using multiplication,
    is to double them repeatedly. So let's try doubling the divisor
    until it no longer fits into the dividend.

    We used negative numbers due to their larger range avoiding overflow
    problems. We do the same here.
 */

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

int HALF_INT_MIN = -1073741824;

class Solution {
public:
    int divide(int dividend, int divisor) {
    	bool invert = false;
    	int result = 0;
    	int q = 0, r, d;

    	if (dividend == INT_MIN && divisor == -1)
    		return INT_MAX;

        if (divisor == 1)
            return dividend;

    	if (dividend > 0) {
    		invert ^= true;
    		dividend = -dividend;
    	}
    	if (divisor > 0) {
    		invert ^= true;
    		divisor = -divisor;
    	}

    	r = dividend;
    	d = divisor;
    	while (divisor >= r) {
    		q = -1;
    		d = divisor;
    		while ((d >= HALF_INT_MIN) && ((d + d) > r)) {
    			d += d;
    			q += q;
    		}
    		result += q;
    		r -= d;
    	}

    	if (!result)
    		return 0;

    	if (invert)
    		result = -result;

    	return -result;
    }
};

struct TestInput {
	int dividend;
	int divisor;
};

int main()
{
	Solution s;
	vector<TestInput> t = {
			{.dividend = 10, .divisor = 3},
			{.dividend = -7, .divisor = -3},
			{.dividend = 1, .divisor = 1},
			{.dividend = -1, .divisor = 1},
			{.dividend = -2147483648, .divisor = 2},
	};

	for (int i = 0; i < t.size(); i++)
		cout << s.divide(t[i].dividend, t[i].divisor) << endl;
	return 0;
}
