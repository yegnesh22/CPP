/*
 * Solution.cpp
 *
 *  Created on: Mar 29, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
	vector<long long> maximumEvenSplit(long long finalSum);
};

vector<long long> Solution::maximumEvenSplit(long long finalSum)
{
	vector<long long> result;
	set<long long> window;
	long long sum = 0;

	if (finalSum & 1)
		return {};

	for (int i = 2; i <= finalSum; i+=2) {
		sum += i;
		window.insert(i);
		if (sum > finalSum) {
			long long diff = sum - finalSum;
			window.erase(diff);
			break;
		}
	}

	return vector<long long> {window.begin(), window.end()};
}

struct ti {
	long long finalSum;
	vector<long long> eo;
	vector<long long> ao;
	ti(long long fs, vector<long long> teo): finalSum(fs), eo(teo) {}
};

vector<ti> t = {
		ti(12, {2,4,6}),
		ti(7, {}),
		ti(28, {4,6,8,10}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->maximumEvenSplit(t[i].finalSum);
		assert(t[i].ao.size() == t[i].eo.size());
		cout << i << " -- pass" << endl;
	}

	return 0;
}
