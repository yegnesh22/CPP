/*
 * Base.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <Base.h>

void Solution::printV(vector<vector<int>> v)
{
	for (int i = 0; i < v.size(); i++) {
		cout << "{" << flush;
		for (int j = 0; j < v[i].size(); j++)
			cout << v[i][j] << " " << flush;
		cout << "}" << flush;
	}
	cout << endl;
}


