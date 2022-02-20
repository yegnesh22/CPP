/*
 * ti.h
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> i;
	int eo;
	int ao;
};

#endif /* TI_H_ */
