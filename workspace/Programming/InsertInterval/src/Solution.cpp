/*
 * Solution.cpp
 *
 *  Created on: Jan 24, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

class Solution {
public:
	virtual vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) = 0;
};

class BasicSolution : public Solution {
public:
#ifdef DEBUG
	void printV(vector<vector<int>>v) {
		cout << "[" << flush;
		for(int i = 0; i < v.size(); i++) {
			cout << "[" << v[i][0] << "," << v[i][1] << "]" << flush;
		}
		cout << "]" << endl;
	}
#endif

	bool isOverlapping(vector<int>i, vector<int> n) {
		return (i[1] >= n[0]);
	}

	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> v;
		bool overlapped = false;

		for (int i = 0; i < intervals.size();) {
			if (isOverlapping(intervals[i], newInterval)) {
				while (i < intervals.size() && !overlapped) {
					if (intervals[i][0] > newInterval[1]) {
						overlapped = true;
						v.push_back(newInterval);
						break;
					}
					newInterval[0] = min(intervals[i][0], newInterval[0]);
					newInterval[1] = max(intervals[i][1], newInterval[1]);
#ifdef DEBUG
					cout << "updating new interval [" << newInterval[0]
						 << "," << newInterval[1] << "]" << endl;
#endif
					i++;
				}

				if (i < intervals.size())
					v.push_back(intervals[i]);
				i++;
			} else {
				v.push_back(intervals[i]);
				i++;
			}
		}

		if (!overlapped)
			v.push_back(newInterval);

#ifdef DEBUG
		printV(v);
#endif
		return v;
	}
};

struct ti {
	vector<vector<int>> i;
	vector<int> n;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
};

vector<ti> t = {
#ifndef DEBUG
		{
				.i = {
						{1,3},
						{6,9},
				},
				.n = {2,5},
				.eo = {
						{1,5},
						{6,9}
				},
		},
		{
				.i = {
						{1,2},
						{3,5},
						{6,7},
						{8,10},
						{12,16},
				},
				.n = {4,8},
				.eo = {
						{1,2},
						{3,10},
						{12,16},
				},
		},
		{
				.i = {},
				.n = {5,7},
				.eo = {
						{5,7},
				},
		},
		{
				.i = {
						{1,2}
				},
				.n = {3,4},
				.eo = {
						{1,2},
						{3,4},
				},
		},
		{
				.i = {
						{3,4}
				},
				.n = {1,2},
				.eo = {
						{1,2},
						{3,4},
				},
		},
		{
				.i = {
						{1,5}
				},
				.n = {2,3},
				.eo = {
						{1,5},
				},
		},
#endif
		{
				.i = {
						{2,5},
						{6,7},
						{8,9},
				},
				.n = {0,1},
				 .eo = {
						 {0,1},
						 {2,5},
						 {6,7},
						 {8,9},
				 },
		},
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->insert(t[i].i, t[i].n);
		cout << "t[" << i << "] -- r:"
				<< ((t[i].ao == t[i].eo) ? "pass" : "fail")
				<< endl;
	}

	return 0;
}
