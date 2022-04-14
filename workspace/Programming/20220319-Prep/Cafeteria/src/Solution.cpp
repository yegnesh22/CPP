/*
 * Solution.cpp
 *
 *  Created on: Apr 2, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
// Write any include statements here

long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S)
{
	long long count = 0;
	long long s = 1;
	long long e;

	sort(S.begin(), S.end());
	for (int i = 0; i < M; i++) {
		e = S[i] - K - 1;
		if (s <= e)
			count += (e - s) / (K + 1) + 1;
		s = S[i] + K + 1;
	}

	if (s <= N)
		count += (N - s) / (K + 1) + 1;
	return count;
}

struct ti {
	vector<long long> S;
	long long N;
	long long K;
	int M;
	long long eo;
	long long ao;
	ti(vector<long long> s, long long n, long long k, long long m, long long e): S(s), N(n), K(k), M(m), eo(e) {}
};

vector<ti> tests = {
		ti({11, 6 , 14}, 15, 2, 3, 1),
		ti({2,6}, 10, 1, 2, 3),
};

int main()
{
	int i = 1;

	for (auto& t: tests) {
		t.ao = getMaxAdditionalDinersCount(t.N, t.K, t.M, t.S);
		assert(t.ao == t.eo);
		cout << i << " -- pass" << endl;
		i++;
	}

	return 0;
}
