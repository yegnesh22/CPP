/*
 * Base.h
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual bool canJump(vector<int>& nums) = 0;
};

#endif /* BASE_H_ */
