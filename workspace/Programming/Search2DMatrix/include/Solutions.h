/*
 * Solutions.h
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#ifndef SOLUTIONS_H_
#define SOLUTIONS_H_

#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

class Solution {
public:
    virtual bool searchMatrix(vector<vector<int>>& matrix, int target) = 0;
};

class BasicSolution:public Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target);
};

#endif /* SOLUTIONS_H_ */
