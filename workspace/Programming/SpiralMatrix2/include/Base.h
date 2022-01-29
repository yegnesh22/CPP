/*
 * Base.h
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void printV(vector<vector<int>> v);
    virtual vector<vector<int>> generateMatrix(int n) = 0;
};

#endif /* BASE_H_ */
