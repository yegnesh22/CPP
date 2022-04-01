/*
 * Solution.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num);
};

vector<long long> Solution::sumOfThree(long long num)
{
	long long mid = num / 3;
	long long bal = num % 3;

	if (bal == 0)
		return {mid-1, mid, mid+1};

	return {};
}

struct ti {
	long long num;
	vector<long long> eo;
	vector<long long> ao;
	ti(long long n, vector<long long> teo): num(n), eo(teo) {}
};

vector<ti> t = {
		ti(33, {10,11,12}),
		ti(4, {}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->sumOfThree(t[i].num);
		assert(t[i].eo == t[i].ao);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
