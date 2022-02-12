/*
 * O1.h
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#ifndef O1_H_
#define O1_H_

#include <bits/stdc++.h>
#include <SolutionBase.h>

/*
 * Algorithm
 * ---------
 * This approach relies on the observation that the rectangle with maximum area will be the maximum of:
 * 1. The widest possible rectangle with height equal to the height of the shortest bar.
 * 2. The largest rectangle confined to the left of the shortest bar(subproblem).
 * 3. The largest rectangle confined to the right of the shortest bar(subproblem).
 */

class O1:public Solution {
private:
    vector<int>::iterator hb;
    int calcArea(vector<int>& h, int start, int end);
public:
    int largestRectangleArea(vector<int>& heights);
};

#endif /* O1_H_ */
