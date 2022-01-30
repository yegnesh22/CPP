/*
 * Base.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#include <Base.h>

void Solution::printV(vector<int> v)
{
	cout << "{" << flush;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ", "<< flush;
	}
	cout << "}" << endl;
}
