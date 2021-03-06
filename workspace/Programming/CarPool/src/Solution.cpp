/*
 * Solution.cpp
 *
 *  Created on: 06-Jan-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

struct test_input {
	vector<vector<int>> trips;
	int capacity;
};

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
    	vector<int> seats(1001, capacity);
    	int nt = trips.size();

    	for (int i = 0; i < nt; i++) {
    		for (int j = trips[i][1]; j < trips[i][2]; j++) {
    			seats[j] -= trips[i][0];
    			if (seats[j] < 0)
    				return false;
    		}
    	}
    	return true;
    }
};

int main()
{
	Solution s;
	vector<test_input> t = {
			{.trips = {{2, 1, 5}, {3, 3, 7}}, .capacity = 4},
			{.trips = {{2, 1, 5}, {3, 3, 7}}, .capacity = 5},
	};

	for (auto it = t.begin(); it != t.end(); it++)
		cout << (s.carPooling((*it).trips, (*it).capacity) ? "possible" : "not possible") << endl;

	return 0;
}

