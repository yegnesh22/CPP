/*
 * Solution.cpp
 *
 *  Created on: Feb 20, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	if (a[0] != b[0])
		return (a[0] < b[0]);
	return (a[1] > b[1]);
}

class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals);
};

int Solution::removeCoveredIntervals(vector<vector<int>>& intervals)
{
	int ns = intervals.size();
	vector<int> t;
    int count = 0;

	// Sort the intervals in the increasing order of start point and
	// decreasing order of endpoints if start points are same.
	sort(intervals.begin(), intervals.end(), compare);

	t = intervals[0];
	for (int i = 1; i < ns; i++) {
		if (intervals[i][1] > t[1]) {
			count++;
			t = intervals[i];
		}
	}

	return count+1; // Increment 1 for the last entry
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> n;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.n = {{1,4},{3,6},{2,8}},
				.eo = 2,
		},
		{
				.n = {{1,4},{2,3}},
				.eo = 1,
		},
		{
				.n = {{1,2},{1,4},{3,4}},
				.eo = 1,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->removeCoveredIntervals(t[i].n);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
