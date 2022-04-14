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

int getArtisticPhotographCount(int N, string C, int X, int Y) {
	// Write your code here
	int count = 0;

	for (int i = 0; i < N; i++) {
		if (C[i] == 'P') {
			// left check
			for (int j = (i - X); ((j >= (i - Y)) && (j >= 0)); j--) {
				if (C[j] == 'A') {
					for (int k = (j - X); ((k >= (j - Y)) && (k >= 0)); k--) {
						if (C[k] == 'B')
							count++;
					}
				}
			}

			// right check
			for (int j = (i + X); ((j <= (i + Y)) && (j < N)); j++) {
				if (C[j] == 'A') {
					for (int k = (j + X); ((k <= (j + Y)) && (k < N)); k++) {
						if (C[k] == 'B')
							count++;
					}
				}
			}
		}
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
