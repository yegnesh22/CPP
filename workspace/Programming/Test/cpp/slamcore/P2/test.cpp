/*
 * Solution.cpp
 *
 *  Created on: Jul 11, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>


double interpolateAcceleration(const std::vector<double>& timestamps,
                               const std::vector<double>& accelerations,
                               const double tquery)
{
	auto u = upper_bound(timestamps.begin(), timestamps.end(), tquery);
	auto l = lower_bound(timestamps.begin(), timestamps.end(), tquery);

	// Correction if tquery has an exact match
	if (*l > tquery)
		l--;

	size_t loff = l - timestamps.begin();
	size_t uoff = u - timestamps.begin();

	double f = (tquery - *l) / (*u - *l);
	return std::lerp(accelerations[loff], accelerations[uoff], f);
}

int main()
{
	const std::vector<double> t {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	const std::vector<double> a {2, 12, 14, 18, 20, 18, 16, 15, 10, 0};
	const double tstamp = 35;

	std::cout << interpolateAcceleration(t, a, tstamp) << std::endl;
	return 0;
}

