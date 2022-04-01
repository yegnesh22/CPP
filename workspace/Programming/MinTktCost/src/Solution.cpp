/*
 * Solution.cpp
 *
 *  Created on: Mar 9, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs);
};

int Solution::mincostTickets(vector<int>& days, vector<int>& costs)
{
	int nd = days.size() - 1;
	int ld = days[nd];
	vector<int> expense(ld+1, 0);
	int j = 0;

	// Starting from 1st day find the minimum cost to travel on each
	// day till the last day.
	for (int i = 1; i <= ld; i++) {
		if (i != days[j])
			expense[i] = expense[i-1];
		else {
			expense[i] = expense[i-1] + costs[0];
			expense[i] = min(expense[max(0, i-7)] + costs[1], expense[i]);
			expense[i] = min(expense[max(0, i-30)] + costs[2], expense[i]);
			j++;
		}
	}
	return expense[ld];
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> d;
	vector<int> c;
	int ao;
	int eo;
};

vector<ti> t ={
		{
				.d = {1,4,6,7,8,20},
				.c = {2,7,15},
				.eo = 11,
		},
		{
				.d = {1,2,3,4,5,6,7,8,9,10,30,31},
				.c = {2,7,15},
				.eo = 17,
		},
		{
				.d = {1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28},
				.c = {3,13,45},
				.eo = 44,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->mincostTickets(t[i].d, t[i].c);
		cout << i << " -- " << result(t[i]) << " ao:" << t[i].ao << " eo:" << t[i].eo << endl;
	}
	return 0;
}
