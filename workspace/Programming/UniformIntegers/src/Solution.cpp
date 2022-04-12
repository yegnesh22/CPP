/*
 * Solution.cpp
 *
 *  Created on: Apr 12, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <cassert>
#include <vector>

using namespace std;

int getUniformIntegerCountInInterval(long long A, long long B) {
	// Write your code here
	vector<long long> b = {
			0,
			1,
			11,
			111,
			1111,
			11111,
			111111,
			1111111,
			11111111,
			111111111,
			1111111111,
			11111111111,
			111111111111,
			1111111111111,
	};
	long long start = A;
	long long firstN;
	int count = 0;
	long long mul;
	int dC = 0;


	while (start) {
		start = start / 10;
		dC++;
	}

	mul = A / b[dC];
	firstN = mul * b[dC];
	if (firstN < A)
		mul++;

	if (mul == 10) {
		mul = 1;
		dC++;
		firstN = b[dC];
	}

	while(firstN <= B) {
		firstN = mul * b[dC];
		mul++;
		if (mul == 10) {
			mul = 1;
			dC++;
		}
		count++;
	}

	count--;
	return count;
}

struct ti {
	long long A;
	long long B;
	int EO;
	int AO;
	ti(long long a, long long b, int eo): A(a), B(b), EO(eo) {}
};

vector<ti> tests = {
		ti(75, 300, 5),
		ti(1, 9, 9),
		ti(999999999999, 999999999999, 1),
		ti(99,111, 2),
};

int main()
{
	int i = 1;

	for (auto& t: tests) {
		t.AO = getUniformIntegerCountInInterval(t.A, t.B);
		assert(t.AO == t.EO);
		cout << i << " -- pass" << endl;
		i++;
	}

	return 0;
}
