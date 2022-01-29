/*
 * SolutionBase.h
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#ifndef SOLUTIONBASE_H_
#define SOLUTIONBASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual int largestRectangleArea(vector<int>& heights) = 0;
};

#endif /* SOLUTIONBASE_H_ */
