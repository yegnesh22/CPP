/*
 * Solution.cpp
 *
 *  Created on: Mar 4, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	bool canReorderDoubled(vector<int>& arr);
};

bool Solution::canReorderDoubled(vector<int>& arr)
{
	multiset<int>::iterator it;
	int al = arr.size();
	multiset<int> lkp;
	int zC = 0;
	int key;

	sort(arr.begin(), arr.end());

	for (int i = 0; i < al; i++) {
		if (arr[i] < 0)
			key = arr[i] * 2;
		else if (arr[i] > 0) {
			if (arr[i] & 0x1) {
				lkp.insert(arr[i]);
				continue;
			}
			key = arr[i] / 2;
		}
		else {
			zC++;
			continue;
		}

		it = lkp.find(key);
		if (it != lkp.end())
			lkp.erase(it);
		else
			lkp.insert(arr[i]);
	}

	return ((lkp.size() == 0) && ((zC & 0x1) == 0));
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> arr;
	bool eo;
	bool ao;
};

vector<ti> t = {
		{
				.arr = {3,1,3,6},
				.eo = false,
		},
		{
				.arr = {2,1,2,6},
				.eo = false,
		},
		{
				.arr = {4,-2,2,-4},
				.eo = true,
		},
		{
				.arr = {-6,-3},
				.eo = true,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->canReorderDoubled(t[i].arr);
		cout << i << " -- " << result(t[i]) << endl;
	}
}
