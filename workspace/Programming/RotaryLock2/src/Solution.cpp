/*
 * Solution.cpp
 *
 *  Created on: Apr 20, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;
// Write any include statements here

long long getMinCodeEntryTime(int N, int M, vector<int> C) {
	// Write your code here
	vector<int> pos(2, 1);
	vector<int> diff(2, 0);
	long long count = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < 2; j++) {
			diff[j] = min(min(N - pos[j], pos[j]) + min(N - C[i], C[i]), abs(pos[j] - C[i]));
		}

		if (diff[0] > diff[1]) {
			cout << "rotating 1 by " << diff[1] << endl;
			pos[1] = C[i];
			count += diff[1];
		} else {
			cout << "rotating 0 by " << diff[0] << endl;
			pos[0] = C[i];
			count += diff[0];
		}
	}

	cout << "returning count " << count << endl;
	return count;
}

struct ti {
	int N;
	int M;
	vector<int> C;
	int EO;
	int AO;
	ti(int N, int M, vector<int> C, int EO): N(N), M(M), C(C), EO(EO) {}
};

vector<ti> tests = {
		ti(3, 3, {1,2,3}, 2),
		ti(10, 4, {9,4,4,8}, 6),
};

int main()
{
	int i = 1;

	for (auto t: tests) {
		t.AO = getMinCodeEntryTime(t.N, t.M, t.C);
		assert(t.AO == t.EO);
		cout << i++ << " -- pass" << endl;
	}

	return 0;
}
