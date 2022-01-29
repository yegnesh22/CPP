/*
 * Solution.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#include <Tree.h>
#include <Solution.h>

void Solution::printR(vector<vector<int>> r)
{
	cout << "{" << flush;
	for (int i  = 0; i < r.size(); i++) {
		cout << "{" << flush;
		for (int j = 0; j < r[i].size(); j++) {
			cout << r[i][j] << "," << flush;
		}
		cout << "}," << flush;
	}
	cout << "}" <<endl;
}

