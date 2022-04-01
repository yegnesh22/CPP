/*
 * Solution.cpp
 *
 *  Created on: Mar 31, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int minimumSum(int num);
};

int Solution::minimumSum(int num)
{
	priority_queue<int, vector<int>, greater<int>> digitQ;

	while (num) {
		digitQ.push(num % 10);
		num /= 10;
	}

	bool indexing = false;
	int num1 = 0;
	int num2 = 0;

	while (!digitQ.empty()) {
		if (indexing)
			num1 = (num1 * 10) + digitQ.top();
		else
			num2 = (num2 * 10) + digitQ.top();
		indexing ^= true;
		digitQ.pop();
	}

	return num1 + num2;
}

struct ti {
	int num;
	int eo;
	int ao;
	ti(int n, int e): num(n), eo(e) {}
};

vector<ti> t = {
		ti(2932, 52),
		ti(4009, 13),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minimumSum(t[i].num);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
