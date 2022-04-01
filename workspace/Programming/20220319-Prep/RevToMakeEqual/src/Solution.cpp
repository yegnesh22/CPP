/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool areTheyEqual(vector<int>& array_a, vector<int>& array_b);
};

bool Solution::areTheyEqual(vector<int>& array_a, vector<int>& array_b)
{
	// Write your code here
	int as = array_a.size();
	int bs = array_b.size();

	if (as != bs)
		return false;

	map <int, int> alkp;
	int zC = 0;

	for (int i = 0; i < as; i++) {
		if (alkp.find(array_a[i]) == alkp.end())
			alkp.insert(pair<int, int> (array_a[i], 1));
		else
			alkp[array_a[i]]++;
	}

	for (int i = 0; i < bs; i++) {
		if (alkp.find(array_b[i]) == alkp.end())
			return false;
		else {
			alkp[array_b[i]]--;
			if (alkp[array_b[i]] == 0)
				zC++;
			if (alkp[array_b[i]] < 0)
				zC--;
		}
	}

	return zC == bs;
}

#define result(X) ((X.ao == X.eo) ? "pass" : "fail")

struct ti {
	vector<int> A;
	vector<int> B;
	bool eo;
	bool ao;
	ti(vector<int> a, vector<int> b, bool e): A(a), B(b), eo(e) {}
};

vector<ti> t = {
		ti({1, 2, 3, 4}, {1, 4, 3, 2}, true),
		ti({1, 2, 3, 4}, {1, 1, 3, 2}, false),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->areTheyEqual(t[i].A, t[i].B);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
