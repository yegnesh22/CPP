/*
 * Base.cpp
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#include <Base.h>

void Solution::printV(vector<vector<int>> l)
{
	for(int i = 0; i < l.size(); i++) {
		for(int j = 0; j < l[i].size(); j++) {
			cout << l[i][j] << " " << flush;
		}
		cout << endl;
	}
}
