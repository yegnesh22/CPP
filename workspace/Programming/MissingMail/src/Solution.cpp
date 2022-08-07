/*
 * Solution.cpp
 *
 *  Created on: Apr 14, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <vector>

using namespace std;
// Write any include statements here

double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
	// Write your code here
	return 0.0;
}

struct ti {
	int N;
	vector<int> V;
	int C;
	double S;
	double EO;
	double AO;
	ti(int n, vector<int> v, int c, double s, double eo): N(n), V(v), C(c), S(s), EO(eo) {}
};

vector<ti> tests = {
		ti(5, {10, 2, 8, 6, 4}, 5, 0.0, 25.0),
		ti(5, {10, 2, 8, 6, 4}, 5, 1.0, 9.0),
		ti(5, {10, 2, 8, 6, 4}, 3, 0.5, 17.0),
		ti(5, {10, 2, 8, 6, 4}, 3, 0.15, 20.10825000),
};

int main()
{
	int i = 1;

	for (auto& t: tests) {
		t.AO = getMaxExpectedProfit(t.N, t.V, t.C, t.S);
		assert(t.AO == t.EO);
		cout << i << " -- pass" << endl;
		i++;
	}

	return 0;
}
