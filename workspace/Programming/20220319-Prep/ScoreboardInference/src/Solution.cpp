/*
 * Solution.cpp
 *
 *  Created on: Apr 9, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int getMinProblemCount(int N, vector<int> S) {
	// Write your code here
	bool containsOdd = false;
	int l = 0;

	for (int i = 0; i < N; i++) {
		if (S[i] & 0x1)
			containsOdd = true;
		l = max(l, S[i]);
	}

	return ((l >> 1) + (containsOdd ? 1 : 0));
}

struct ti {
	vector<int> S;
	int N;
	int EO;
	int AO;
	ti(vector<int>s, int n, int eo): S(s), N(n), EO(eo) {}
};

vector<ti> t = {
		ti({1, 2, 3, 4, 5, 6}, 6, 4),
		ti({4, 3, 3, 4}, 4, 3),
		ti({2, 4, 6, 8}, 4, 4),
};

int main()
{
	int i = 1;

	for (auto &test: t) {
		test.AO = getMinProblemCount(test.N, test.S);
		assert(test.AO == test.EO);
		cout << i << " -- pass" << endl;
	}
	return 0;
}
