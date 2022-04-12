/*
 * Solution.cpp
 *
 *  Created on: Apr 10, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int largestInteger(int num) {
		priority_queue<int> oddq, evenq;
		vector<bool> parity;
		int val = 0;
		int nd = 0;
		int d;

		while (num) {
			d = num % 10;
			num = num / 10;
			if (d & 0x1) {
				oddq.push(d);
				parity.push_back(false);
			}
			else {
				evenq.push(d);
				parity.push_back(true);
			}
			nd++;
		}

		for (int i = nd - 1; i >= 0; i--) {
			if (parity[i]) {
				d = evenq.top();
				evenq.pop();
			} else {
				d = oddq.top();
				oddq.pop();
			}
			val = (val * 10) + d;
		}

		cout << "returning val:" << val << endl;
		return val;
	}
};

struct ti {
	int num;
	int eo;
	int ao;
	ti(int N, int E): num(N), eo(E) {}
};

vector<ti> tests = {
		ti(1234, 3412),
		ti(65875, 87655),
};

int main()
{
	Solution* s = new Solution();
	int i = 1;
	for (auto& t: tests) {
		t.ao = s->largestInteger(t.num);
		assert(t.ao == t.eo);
		cout << i << " -- pass" << endl;
	}
}
