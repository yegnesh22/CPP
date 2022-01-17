/*
 * Solution.cpp
 *
 *  Created on: Jan 16, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	int numSeats = seats.size() - 1;
    	queue<int> dist;
    	int gs = -1;
    	int ge = -1;

    	dist.push(0);

    	for (int i = 0; i <= numSeats; i++) {
    		if (!seats[i]) {
    			if (gs == -1)
    				gs = i;
    			ge = i;
    		} else {
    			int last = dist.front();
    			// Push the max distance in he queue
    			int d;
    			// If the gap is in the beginning of the lane, the max distance
    			// happens when the person occupies the left most place.
    			// In which case the max distance will be number of vacant
    			// seats - 1.
    			if (gs == 0)
    				d = ge - gs + 1;
    			else {
    				// If the gap is in the middle, then the max distance is the
    				// number of vacant seats / 2. This happens when the person
    				// occupies the seat right in the middle.
    				// If there are odd number of vacant seats, the max dist is
    				// vacant seats + 1 / 2.
    				// If there are even number of vacant seats, the max dist is
    				// vacant seats / 2 (as there will not be an exact middle seat.
    				d = (ge - gs + 1);
    				if (d & 1)
    					d = d / 2 + 1;
    				else
    					d = d / 2;
    			}

    			// Push the distance if it is greater than the last calculated
    			// max dist.
    			if (d > last) {
    				dist.pop();
    				dist.push(d);
    			}
				gs = -1;
				ge = -1;
    		}
    	}

    	// One additional processing for last location
		int last = dist.front();
		int d = ge - gs + 1;
		// Push the max value
		if (d > last) {
			dist.pop();
			dist.push(d);
		}

		return dist.front();
    }
};

struct TestInputs {
	vector<int> i;
	int eo;
	int ao;
};

int main()
{
	vector<TestInputs> t = {
			{.i = {1,0,0,0,1,0,1}, .eo = 2},
			{.i = {1,0,0,0}, .eo = 3},
			{.i = {0,1}, .eo = 1},
			{.i = {1,0,1}, .eo = 1},
			{.i = {0,0,1,0,1,1}, .eo = 2},
			{.i = {0,1,1,1,0,0,1,0,0}, .eo = 2},
			{.i = {0,1,0,1,0}, .eo = 1},
			{.i = {1,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0}, .eo = 5},
			{.i = {0,0,0,0,0,0,0,1,0,0,0,0}, .eo = 7},
			{.i = {0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,1}, .eo = 3},
	};
	Solution s;

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s.maxDistToClosest(t[i].i);
		cout << "t[" << i << "] eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = "<< ((t[i].eo == t[i].ao) ? "pass" : "fail")
				<< endl;
	}
	return 0;
}
