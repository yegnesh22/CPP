/*
 * O1.cpp
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#include <O1.h>
#include <map>

int Solution::carFleet(int target, vector<int>& position, vector<int>& speed)
{
	int nc = position.size();
	map<int, double> cData;
	int fleet = 0;
	double last = 0;
	double tt;

	for (int i = 0; i < nc; i++) {
		tt = (double) (target - position[i]) / speed[i];
		cData.insert(make_pair(position[i], tt));
	}

	for (map<int, double>::reverse_iterator it = cData.rbegin(); it != cData.rend(); it++) {
		if (last < it->second) {
			fleet++;
			last = it->second;
		}
	}

	return fleet;
}

