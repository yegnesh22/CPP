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

int getMinimumDeflatedDiscCount(int N, vector<int> R) {
	// Write your code here
	vector<int> M = R;
	int count = 0;

	for (int i = 1; i < N; i++) {
		if (M[i] <= M[i-1]) {
			for (int j = (i-1); j >= 0; j--) {
				if (M[j] >= M[j+1]) {
					M[j] = M[j+1] - 1;
					if (M[j] <= 0) {
						cout << "returning count -1" << endl;
						return -1;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		if (R[i] != M[i])
			count++;
	}

	cout << "returning count:" << count << endl;
	return count;
}

struct ti {
	int N;
	vector<int> R;
	int EO;
	int AO;
	ti(int n, vector<int> r, int eo): N(n), R(r), EO(eo) {}
};

vector<ti> tests = {
		ti(5, {2, 5, 3, 6, 5}, 3),
		ti(3, {100, 100, 100}, 2),
		ti(4, {6, 5, 4, 3}, -1),
};

int main()
{
	int i = 1;

	for (auto& t: tests) {
		t.AO = getMinimumDeflatedDiscCount(t.N, t.R);
		assert(t.AO == t.EO);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
