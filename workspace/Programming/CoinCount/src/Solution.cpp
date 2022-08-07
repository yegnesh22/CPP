/*
 * Solution.cpp
 *
 *  Created on: Jul 11, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <cassert>

using namespace std;

bool getMinCount(vector<int> cd, int& bal, vector<int>& ccount) {
	int m = INT_MAX;

	if (bal != 0 && bal < cd[0])
		return false;

	if (bal == 0)
		return true;

	for (int i = cd.size()-1; i >= 0; i--) {
		int t = bal - cd[i];
		bool c = getMinCount(cd, t, ccount);
		if (c)
			m = min(m, ccount[bal-cd[i]] + 1);
	}

	if (m == INT_MAX)
		return false;

	ccount[bal] = m;
	return true;
}

int minCoins(vector<int> cd, int target)
{
	vector<int> ccount(target+1, 0);

	sort(cd.begin(), cd.end());
	return getMinCount(cd, target, ccount) ? ccount[target] : -1;
}

struct ti {
	vector<int> cd;
	int tv;
	int eo;
	int ao;
	ti(vector<int> a, int b, int e): cd(a), tv(b), eo(e) {}
};

vector<ti> tests = {
		ti({10, 5}, 3, -1),
		ti({7, 6, 1}, 12, 2),
		ti({25, 10, 5}, 65, 4),
};

int main()
{
	int i = 0;
	for (auto t: tests) {
		t.ao = minCoins(t.cd, t.tv);
		assert(t.ao == t.eo);
		cout << i++ << " pass" << endl;
	}

	return 0;
}
