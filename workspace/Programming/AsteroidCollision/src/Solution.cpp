/*
 * Solution.cpp
 *
 *  Created on: Feb 6, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	vector<int> eo;
	vector<int> ao;
};

class Solution {
public:
	void placeAsteroid(int a, vector<int>& r);
    vector<int> asteroidCollision(vector<int>& asteroids);
};

void Solution::placeAsteroid(int a, vector<int>& r)
{
	if (a > 0) {
		r.push_back(a);
		return;
	}

	int as = abs(a);
	int top;
	int ts;
	while (!r.empty()) {
		top = r.back();
		if (top > 0){
			ts = abs(top);
			if (ts < as) {
				r.pop_back();
				continue;
			} else if (ts == as) {
				r.pop_back();
				return;
			} else {
				return;
			}
		}
		if (top < 0) {
			r.push_back(a);
			return;
		}
	}

	r.push_back(a);
	return;
}

vector<int> Solution::asteroidCollision(vector<int>& asteroids)
{
	int na = asteroids.size();
	vector<int> r;

	for (int i = 0; i < na; i++)
		placeAsteroid(asteroids[i], r);

	return r;
}

vector<ti> t = {
		{
				.n = {5,10,-5},
				.eo = {5,10},
		},
		{
				.n = {8,-8},
				.eo = {},
		},
		{
				.n = {10,2,-5},
				.eo = {10},
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->asteroidCollision(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}
}
