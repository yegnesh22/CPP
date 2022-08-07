/*
 * Solution.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#ifndef INCLUDE_BASE_H_
#define INCLUDE_BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Base {
	public:
		virtual vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) = 0;
		template <typename __t>
		void print2DV(vector<vector<__t>> v)
		{
			cout << "[" << flush;
			for (int i = 0; i < v.size(); i++) {
				cout << "[" << flush;
				for (int j = 0; j < v[i].size(); j++) {
					cout << v[i][j] << " " << flush;
				}
				cout << "]" << flush;
			}
			cout << "]" << endl;
		}

		template <typename __t>
		void print1DV(vector<__t> v)
		{
			cout << "[" << flush;
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " " << flush;
			}
			cout << "]" << endl;
		}
};

#endif /* INCLUDE_BASE_H_ */
