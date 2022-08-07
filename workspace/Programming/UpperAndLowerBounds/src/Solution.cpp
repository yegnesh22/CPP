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

using namespace std;

int main()
{
	vector<double> t {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	vector<double> a {2, 12, 14, 18, 20, 18, 16, 15, 10, 0};
	double tstamp = 30;

	auto l = lower_bound(t.begin(), t.end(), tstamp);
	auto u = upper_bound(t.begin(), t.end(), tstamp);

	if (*l > tstamp)
		l--;

	size_t loff = l - t.begin();
	size_t uoff = u - t.begin();

	double factor = (tstamp - *l) / (*u - *l);
	cout << factor << endl;
	double tinst = std::lerp(a[loff], a[uoff], factor);
	cout << tinst << endl;
	return 0;
}
