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
    virtual int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) = 0;
    void printV(vector<vector<int>> l);
};


#endif /* BASE_H_ */
