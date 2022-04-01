/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> CountSubarrays(vector <int> arr);
};

vector<int> Solution::CountSubarrays(vector <int> arr) {
	// Write your code here
	int as = arr.size();
	vector<int> res(as, 1);
	bool endCheck;

	for (int i = 0; i < as; i++) {
		endCheck = false;
		for (int j = i - 1; j >= 0 && !endCheck; j--) {
			if (arr[i] > arr[j])
				res[i]++;
			else
				endCheck = true;
		}
		endCheck = false;
		for (int j = i + 1; j < as && !endCheck; j++) {
			if (arr[i] > arr[j])
				res[i]++;
			else
				endCheck = true;
		}
	}

	return res;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> arr;
	vector<int> eo;
	vector<int> ao;
	ti(vector<int> a, vector<int> e): arr(a), eo(e) {}
};

vector<ti> t = {
		ti({3, 4, 1, 6, 2}, {1, 3, 1, 5, 1}),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->CountSubarrays(t[i].arr);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
