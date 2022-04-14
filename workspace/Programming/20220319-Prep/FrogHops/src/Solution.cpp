/*
 * Solution.cpp
 *
 *  Created on: Apr 13, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;
// Write any include statements here

// Logic: If ith frog is the farthest from Nth pad, i.e with earliest index
// needs N - P[i] jumps to reach the shore. If there are F - 1 frogs in front
// of it, ith frog can skin F - 1 jumps, but those F - 1 frogs have to jump
// F - 1 jumps

long long getSecondsRequired(long long N, int F, vector<long long> P) {
	// Write your code here
	long long mP = P[0];
	for (int i = 1; i < F; i++)
		mP = min(mP, P[i]);
	return N - mP;
}

struct ti {
	long long N;
	int F;
	vector<long long> P;
	long long EO;
	long long AO;
	ti(long long n, int f, vector<long long> p, long long eo): N(n), F(f), P(p), EO(eo) {}
};

vector<ti> tests = {
		ti(3, 1, {1}, 2),
		ti(6, 3, {5, 2, 4}, 4),
};

int main()
{
	int i = 1;

	for (auto& t: tests) {
		t.AO = getSecondsRequired(t.N, t.F, t.P);
		assert(t.AO == t.EO);
		cout << i << " -- pass" << endl;
		i++;
	}

	return 0;
}
