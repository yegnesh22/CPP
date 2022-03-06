/*
 * Solution.cpp
 *
 *  Created on: Mar 5, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//#define DEBUG

class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations);
};

int Solution::minRefuelStops(int target, int startFuel, vector<vector<int>>& stations)
{
	int ns = stations.size();
	priority_queue<int> gas;
	int tank = startFuel;
	int stops = 0;
	int loc = 0;

	if (ns == 0) {
		if (startFuel < target)
			return -1;
		else
			return 0;
	}

	if (startFuel < stations[0][0]) // Not enough fuel to reach the first station
		return -1;

	for (int i = 0; i < ns; i++) {
		if ((loc >= target) || (loc + tank >= target))
			return stops;
		tank = tank - (stations[i][0] - loc);
#ifdef DEBUG
		cout << "1 --  check tank:" << tank << endl;
#endif
		while (!gas.empty() && tank < 0) {
			tank += gas.top();
#ifdef DEBUG
			cout << "1 -- refuelled " << gas.top() << " tank:" << tank << endl;
#endif
			gas.pop();
			stops++;
		}
		if (tank < 0) // No more gas to reach the destn
			return -1;
		gas.push(stations[i][1]);
		loc = stations[i][0];
#ifdef DEBUG
		cout << "1 -- Moved to " << loc << endl;
#endif
	}

	while (loc < target) { // Not reached the destination
#ifdef DEBUG
		cout << "2 --  check tank:" << tank << endl;
#endif
		while (!gas.empty() && tank <= 0) {
			tank += gas.top();
#ifdef DEBUG
			cout << "2 -- refuelled " << gas.top() << " tank:" << tank << endl;
#endif
			gas.pop();
			stops++;
		}
		if (tank <= 0)
			return -1;
		loc += tank;
		tank = 0;
#ifdef DEBUG
		cout << "2 -- Moved to " << loc << endl;
#endif
	}

	return stops;
}

struct ti {
	int target;
	int startFuel;
	vector<vector<int>> stations;
	int eo;
	int ao;
};

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

vector<ti> t = {
#ifndef DEBUG
		{
				.target = 1,
				.startFuel = 1,
				.stations = {},
				.eo = 0,
		},
		{
				.target = 100,
				.startFuel = 1,
				.stations = {{10,100}},
				.eo = -1,
		},
		{
				.target = 100,
				.startFuel = 10,
				.stations = {{10,60},{20,30},{30,30},{60,40}},
				.eo = 2,
		},
		{
				.target = 1000,
				.startFuel = 83,
				.stations = {
						{25,27},{36,187},{140,186},{378,6},{492,202},
						{517,89},{579,234},{673,86},{808,53},{954,49},
				},
				.eo = -1,
		},
#endif
		{
				.target = 100,
				.startFuel = 50,
				.stations = {{25,25},{50,50}},
				.eo = 1,
		}
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minRefuelStops(t[i].target, t[i].startFuel, t[i].stations);
		cout << t[i].ao << endl;
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}

