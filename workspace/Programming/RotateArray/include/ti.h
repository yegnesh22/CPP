/*
 * ti.h
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.eo == x.nums) ? "pass" : "fail")

struct ti {
	vector<int> nums;
	int k;
	vector<int> eo;
};


#endif /* TI_H_ */
