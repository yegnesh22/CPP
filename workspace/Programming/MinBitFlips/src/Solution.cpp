/*
 * Solution.cpp
 *
 *  Created on: Apr 4, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
	int minBitFlips(int start, int goal);
};

int Solution::minBitFlips(int start, int goal)
{
	int r = start ^ goal;
	bitset<32> s(r);

	return s.count();
}

struct ti {
	int start;
	int goal;
	int eo;
	int ao;
	ti(int s, int g, int e): start(s), goal(g), eo(e) {}
};

vector<ti> t = {
		ti(10, 7, 3),
		ti(3, 4, 3),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minBitFlips(t[i].start, t[i].goal);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}
	return 0;
}
