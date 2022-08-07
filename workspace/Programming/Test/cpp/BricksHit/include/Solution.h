/*
 * Solution.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#ifndef INCLUDE_SOLUTION_H_
#define INCLUDE_SOLUTION_H_

#include <Base.h>

class Solution: public Base {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits);
    void checkState(vector<vector<int>>& g, int r, int c, int nr, int nc);
    int calcBricks(vector<vector<int>>& grid);
};

#endif /* INCLUDE_SOLUTION_H_ */
