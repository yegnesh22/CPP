/*
 * Base.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
	virtual int carFleet(int target, vector<int>& position, vector<int>& speed) = 0;
};

#endif /* BASE_H_ */
