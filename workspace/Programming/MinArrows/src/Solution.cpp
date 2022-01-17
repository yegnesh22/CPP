/*
 * Solution.cpp
 *
 *  Created on: Jan 13, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Algorithm
 * Sort the balloons by end coordinate x_end.
 * Initiate the end coordinate of a balloon which ends first :
 * first_end = points[0][1].
 * Initiate number of arrows: arrows = 1.
 * Iterate over all balloons:
 * 	If the balloon starts after first_end:
 * 		Increase the number of arrows by one.
 * 		Set first_end to be equal to the end of the current balloon.
 * Return arrows.
 */

class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {
		int num_points = points.size() - 1;

		sort(points.begin(), points.end(),
				[](const vector<int>& o1, const vector<int>& o2) {
			return (o1[1] < o2[1]);
		});

		int first_end = points[0][1];
		int arrows = 1;

		for (int i = 1; i <= num_points; i++) {
			if (points[i][0] > first_end) {
				first_end = points[i][1];
				arrows++;
			}
		}
		return arrows;
	}
};

struct TestInput {
	vector<vector<int>> p;
	int eo;
	int ao;
};

int main()
{
	vector<TestInput> t = {
#ifndef DEBUG
			{.p = {{10,16},{2,8},{1,6},{7,12}}, .eo = 2},
			{.p = {{1,2},{2,3},{3,4},{4,5}}, .eo = 2},
			{.p = {{1,2},{3,4},{5,6},{7,8}}, .eo = 4},
#endif
			{.p = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}}, .eo = 2},
	};
	Solution s;

	for (size_t i = 0; i < t.size(); i++) {
		t[i].ao = s.findMinArrowShots(t[i].p);
		cout << "t[" << i << "] - eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}

