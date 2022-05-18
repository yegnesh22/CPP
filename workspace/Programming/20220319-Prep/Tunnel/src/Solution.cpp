/*
 * Solution.cpp
 *
 *  Created on: Apr 24, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> tdata;

struct cmp {
	bool operator() (const tdata& a, const tdata& b) const {
		return a.first > b.first;
	}
};

long long getSecondsElapsed(long long C, int N, vector<long long> A, vector<long long> B, long long K) {
	// Write your code here
	priority_queue<tdata, vector<tdata>, cmp> twq;
	long long tlen = 0;
	long long last_end = 0;

	for (int i = 0; i < N; i++) {
		long long len = B[i] - A[i];
		twq.push(tdata(A[i], len));
		tlen += len;
		if (last_end < B[i])
			last_end = B[i];
	}

	long long diff = K % tlen;
	long long telapsed = (K / tlen) * C;

	while (diff > 0) {
		tdata nt = twq.top();
		twq.pop();
		diff -= nt.second;
		if (diff <= 0) {
			telapsed += nt.first + nt.second + diff;
			return telapsed;
		}
	}

	return telapsed - C + last_end;
}

struct ti {
	long long C;
	int N;
	vector<long long> A;
	vector<long long> B;
	long long K;
	long long EO;
	long long AO;
	ti(long long C, int N, vector<long long> A, vector<long long> B, long long K, long long EO): C(C), N(N), A(A), B(B), K(K), EO(EO) {}
};

vector<ti> tests = {
		ti(10, 2, {1, 6}, {3, 7}, 7, 22),
		ti(10, 2, {1, 6}, {3, 7}, 6, 17),
		ti(10, 2, {1, 6}, {3, 7}, 3, 7),
		ti(10, 2, {1, 6}, {3, 7}, 2, 3),
		ti(50, 3, {39, 19, 28}, {49, 27, 35}, 15, 35),
};

int main()
{
	int i = 0;

	for (auto& t: tests) {
		t.AO = getSecondsElapsed(t.C, t.N, t.A, t.B, t.K);
		assert(t.AO == t.EO);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
