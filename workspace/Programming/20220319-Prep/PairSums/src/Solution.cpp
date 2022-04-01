/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int numberOfWays(vector<int>& arr, int k);
};

int Solution::numberOfWays(vector<int>& arr, int k) {
	// Write your code here
	int as = arr.size();
	map<int, int> lkp;
	int res = 0;
	int key;

	for (int i = 0; i < as; i++) {
		key = k - arr[i];
		if (lkp.find(key) != lkp.end()) {
			//cout << "found key: " << key << " count:" << lkp[key] << endl;
			res += lkp[key];
		}
		if (lkp.find(arr[i]) == lkp.end())
			lkp.insert(pair<int, int>(arr[i], 1));
		else
			lkp[arr[i]]++;
	}
	//cout << res << endl;
	return res;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	vector<int> arr;
	int n;
	int k;
	int eo;
	int ao;
	ti(vector<int> A, int N, int K, int EO): arr(A), n(N), k(K), eo(EO) {}
};

vector<ti> t = {
		ti({1, 2, 3, 4, 3}, 5, 6, 2),
		ti({1, 5, 3, 3, 3}, 5, 6, 4),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->numberOfWays(t[i].arr, t[i].k);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
