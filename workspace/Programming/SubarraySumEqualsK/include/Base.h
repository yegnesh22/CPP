/*
 * Base.h
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
    virtual int subarraySum(vector<int>& nums, int k) = 0;
};

#endif /* BASE_H_ */
