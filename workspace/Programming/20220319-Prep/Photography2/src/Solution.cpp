/*
 * Solution.cpp
 *
 *  Created on: Apr 9, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Sliding window approach
long long getArtisticPhotographCount(int N, string C, int X, int Y) {
	// Write your code here
	long long count = 0;
	queue<int> lP;
	queue<int> lB;
	queue<int> rP;
	queue<int> rB;
	int i = 0;
	int lS = i - Y;
	int lE = i - X;
	int rS = i + X;
	int rE = i + Y;

	for (int k = rS; k < rE; k++) {
		if (C[k] == 'B')
			rB.push(k);
		if (C[k] == 'P')
			rP.push(k);
	}

	while (i < N) {
		if (!lP.empty() && (i - lP.front() > Y))
			lP.pop();

		if (!lB.empty() && (i - lB.front() > Y))
			lB.pop();

		if (lE >= 0) {
			if (C[lE] == 'P')
				lP.push(lE);
			if (C[lE] == 'B')
				lB.push(lE);
		}

		if (!rP.empty() && ((rP.front() - i) < X))
			rP.pop();
		if (!rB.empty() && ((rB.front() - i) < X))
			rB.pop();

		if (rE < N) {
			if (C[rE] == 'P')
				rP.push(rE);
			if (C[rE] == 'B')
				rB.push(rE);
		}

		if (C[i] == 'A')
			count +=  ((lP.size() * rB.size()) + (lB.size() * rP.size()));
		lS++;
		lE++;
		rS++;
		rE++;
		i++;
	}
	return count;
}

struct ti {
	string C;
	int N;
	int X;
	int Y;
	int EO;
	int AO;
	ti(string c, int n, int x, int y, int eo): C(c), N(n), X(x), Y(y), EO(eo) {}
};

vector<ti> t = {
		ti("APABA", 5, 1, 2, 1),
		ti("APABA", 5, 2, 3, 0),
		ti(".PBAAP.B", 8, 1, 3, 3),
};

int main()
{
	int i = 1;

	for (auto& test: t) {
		test.AO = getArtisticPhotographCount(test.N, test.C, test.X, test.Y);
		assert(test.AO == test.EO);
		cout << i << " -- pass" << endl;
		i++;
	}

	return 0;
}
