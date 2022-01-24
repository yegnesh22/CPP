/*
 * Solution.cpp
 *
 *  Created on: Jan 23, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define print(x) cout << #x << "=" << x << endl

class Solution {
public:
    virtual vector<int> sequentialDigits(int low, int high) = 0;
};

bool compare(int a, int b) {
	return a < b;
}

class BasicSolution : public Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int> v;

		for (int d = 1; d < 9; d++) {
			int num = 0;
			int cd = d;
			while (true) {
				num = num * 10 + cd;
				cd++;
				if (num <= high && num >= low)
					v.push_back(num);
				if ((num > high) || (cd >= 10))
					break;
			}
		}

		sort(v.begin(), v.end(), compare);
		return v;
	}
};

struct TI {
	int l;
	int h;
	vector<int> eo;
	vector<int> ao;
};

vector<TI> t = {
		{
				.l = 100,
				.h = 300,
				.eo = {123,234},
		},
		{
				.l = 1000,
				.h = 13000,
				.eo = {1234,2345,3456,4567,5678,6789,12345},
		},
};


int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->sequentialDigits(t[i].l, t[i].h);
		cout << i << ": r=" << ((t[i].eo == t[i].ao) ? "pass" : "fail") << endl;
	}
	return 0;
}
