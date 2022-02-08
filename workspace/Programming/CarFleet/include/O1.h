/*
 * O1.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#ifndef O1_H_
#define O1_H_

#include <Base.h>

struct cD {
	int pos;
	int speed;
};

class Solution : public Base {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed);
};

#endif /* O1_H_ */
