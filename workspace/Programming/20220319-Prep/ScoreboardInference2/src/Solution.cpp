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
	vector<bool> rem(3, false);
	bool hasOne = false;
	int l3 = 0;
	int l = 0;

	for (int i = 0; i < N; i++) {
		int m = S[i] % 3;
		hasOne |= (S[i] == 1);
		rem[m] = true;
		if (m == 0)
			l3 = max(l3, S[i]);
		l = max(l, S[i]);
	}

	int count1, count2, count3;
	count3 = l / 3;
	count1 = ((rem[1]) ? 1 : 0);
	count2 = ((rem[2]) ? 1 : 0);

	// Replace a 3 with a 2 and 1 as 2 and 1 are required
	if ((l % 3) == 0 && count1 == 1 && count2 == 1) {
		count3--;
		return count1 + count2 + count3;
	}

	// If we dont have 1 as the score, scores with remainder 1
	// can be achieved by 1,3 with 2, 2.
	if (!hasOne) {
		count1--;
		count2++;
	}

	// Remove an additional 3 if we have 2 2s and max has a remainder 1
	// but dont require that additional 3 for representing a scorewhich
	// is the largest multiple of 3
	if ((((l / 3) * 3) > l3) && ((l % 3) == 1) && (count2 == 2) )
		count3--;

	return count3 + count2 + count1;
}

struct ti {
	vector<int> S;
	int N;
	int EO;
	int AO;
	ti(vector<int>s, int n, int eo): S(s), N(n), EO(eo) {}
};

vector<ti> t = {
		ti({1, 2, 3, 4, 5}, 5, 3),
		ti({4, 3, 3, 4}, 4, 2),
		ti({2, 4, 6, 8}, 4, 4),
		ti({2, 4, 6, 7}, 4, 4),
		ti({8}, 1, 3),
};

int main()
{
	int i = 1;

	for (auto &test: t) {
		test.AO = getMinProblemCount(test.N, test.S);
		assert(test.AO == test.EO);
		cout << i << " -- pass" << endl;
		i++;
	}
	return 0;
}
