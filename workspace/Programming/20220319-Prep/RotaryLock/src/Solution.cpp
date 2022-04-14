/*
 * Solution.cpp
 *
 *  Created on: Apr 8, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
	// Write your code here
	int cur = 1;
	long long nSteps;
	long long t = 0;

	for (int i = 0; i < M; i++) {
		if (cur > C[i])
			nSteps = min(cur - C[i], N + C[i] - cur);
		else if (cur < C[i])
			nSteps = min(N + cur - C[i], C[i] - cur);
		else
			nSteps = 0;
		cur = C[i];

		t += nSteps;
	}

	cout << "returning " << t << endl;
	return t;
}

struct ti {
	vector<int> C;
	int N;
	int M;
	long long EO;
	long long AO;
	ti(vector<int> c, int n, int m, int eo): C(c), N(n), M(m), EO(eo) {}
};

vector<ti> t = {
		ti({3,3,3}, 10, 3, 2)
};

int main()
{
	for (int i = 0; i < t.size(); i++) {
		t[i].AO = getMinCodeEntryTime(t[i].N, t[i].M, t[i].C);
		assert(t[i].AO == t[i].EO);
		cout << i << " -- pass" << endl;
	}
}
