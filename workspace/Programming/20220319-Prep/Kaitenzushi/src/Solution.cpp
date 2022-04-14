/*
 * Solution.cpp
 *
 *  Created on: Apr 12, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;
// Write any include statements here

int getMaximumEatenDishCount(int N, vector<int> D, int K) {
	// Write your code here
	queue<pair<int, int>> eatenDishOrder;
	set<int> eatenDish;
	int dishC = 0;
	int i = 0;

	for (int i = 0; i < N; i++) {
		if (eatenDish.find(D[i]) == eatenDish.end()) {
			dishC++;
			eatenDish.insert(D[i]);
			eatenDishOrder.push({i, D[i]});
			if (eatenDishOrder.size() > K) {
				pair<int, int>firstEaten = eatenDishOrder.front();
				eatenDishOrder.pop();
				eatenDish.erase(firstEaten.second);
			}
		}
	}

	cout << "returning " << dishC << endl;
	return dishC;
}

struct ti {
	int N;
	vector<int> D;
	int K;
	int EO;
	int AO;
	ti(int n, vector<int> d, int k, int eo): N(n), D(d), K(k), EO(eo) {}
};

vector<ti> tests = {
		ti(6, {1, 2, 3, 3, 2, 1}, 1, 5),
		ti(6, {1, 2, 3, 3, 2, 1}, 2, 4),
		ti(7, {1, 2, 1, 2, 1, 2, 1}, 2, 2),
};

int main()
{
	int i = 0;

	for (auto& t: tests) {
		t.AO = getMaximumEatenDishCount(t.N, t.D, t.K);
		assert(t.AO == t.EO);
		cout << i << " -- pass" << endl;
	}

	return 0;
}
