/*
 * Base.h
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    virtual void rotate(vector<int>& nums, int k) = 0;
    void printV(vector<int> v);
};

#endif /* BASE_H_ */
