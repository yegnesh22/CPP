/*
 * Solution.cpp
 *
 *  Created on: Mar 30, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	long long smallestNumber(long long num);
};

long long Solution::smallestNumber(long long num)
{
	long long val = 0;

    if (num == 0)
        return 0;

	if (num < 0) {
		priority_queue<long long> digits;
		num = abs(num);
		while (num > 0) {
			digits.push(num % 10);
			num /= 10;
		}
		while (!digits.empty()) {
			val = val * 10 + digits.top();
			digits.pop();
		}
		val = -val;
	} else {
		priority_queue<long long, vector<long long>, greater<long long>> digits;
		while (num > 0) {
			digits.push(num % 10);
			num /= 10;
		}
		long long mul = 1;
		while (digits.top() == 0) {
			mul *= 10;
			digits.pop();
		}
		val = digits.top() * mul;
		digits.pop();
		while (!digits.empty()) {
			val = val * 10 + digits.top();
			digits.pop();
		}
	}

	return val;
}

struct ti {
	long long num;
	long long eo;
	long long ao;
	ti(long long n, long long e): num(n), eo(e) {}
};

vector<ti> t = {
		ti(310, 103),
		ti(-7605, -7650),
		ti(0,0),
		ti(1000000000000000, 1000000000000000),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->smallestNumber(t[i].num);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
