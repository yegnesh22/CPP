/*
 * Solution.cpp
 *
 *  Created on: Jan 21, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	virtual int canCompleteCircuit(vector<int>& gas, vector<int>& cost) = 0;
};

class OptimizedSolution:public Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int ns = gas.size();
		int total_tank = 0;
		int current_tank = 0;
		int starting_point = 0;

		cout << "Optimized version -- " << endl;
		for (int i = 0; i < ns; i++) {
			total_tank += gas[i] - cost[i];
			current_tank += gas[i] - cost[i];
			if (current_tank < 0) {
				starting_point = i + 1;
				current_tank = 0;
			}
		}

		return (total_tank >= 0 ? starting_point : -1);
	}
};

class BFSolution:public Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int ns = gas.size();

		cout << "BruteForce version -- " << endl;
		for (int i = 0; i < ns; i++) {
			// find the starting point
			if (gas[i] >= cost[i]) { // This is a possible starting point
				int f = gas[i];
				int s = i;
				int d = s;
				while (f >= 0) {
					f = f - cost[s % ns];
					if (f < 0) // Cannot reach the next destn
						break;
					f += gas[(s + 1) % ns];
					s = (s + 1) % ns;
					//cout << "destn : " << s << " rf:" << f << endl;
					if (s == d) // Reached the destination
						break;
				}
				if (s == d && f >= 0)
					return d;
			}
		}
		return -1;
	}
};

struct TestInput {
	vector<int> g;
	vector<int> c;
	int eo;
	int ao;
};

int main()
{
	vector<TestInput> t = {
			{
				.g = {1,2,3,4,5},
				.c = {3,4,5,1,2},
				.eo = 3,
			},
			{
				.g = {2,3,4},
				.c = {3,4,3},
				.eo = -1,
			},
	};
	Solution *s = new BFSolution();
	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->canCompleteCircuit(t[i].g, t[i].c);
		cout << "T[" << i << "] - eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass":"false")
				<< endl;
	}

	delete s;

	s  = new OptimizedSolution();
	TestInput nt;
	nt.g.resize(100000);
	nt.c.resize(100000);
	nt.g[99999] = 2;
	nt.c[99998] = 1;
	nt.eo = 99999;
	nt.ao = s->canCompleteCircuit(nt.g, nt.c);
	cout << "NT - eo = " << nt.eo
			<< " ao = " << nt.ao
			<< " result = " << ((nt.ao == nt.eo) ? "pass":"false")
			<< endl;

	delete s;

	return 0;
}
