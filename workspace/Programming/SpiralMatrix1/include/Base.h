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
	void printV(vector<int> v);
    virtual vector<int> spiralOrder(vector<vector<int>>& matrix) = 0;
};

#endif /* BASE_H_ */
