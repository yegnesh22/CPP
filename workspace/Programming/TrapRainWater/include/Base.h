/*
 * Base.h
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual int trap(vector<int>& height) = 0;
};

#endif /* BASE_H_ */
