/*
 * ti.h
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) (x.eo == x.ao ? "pass" : "fail")

struct ti {
	int i;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
};

#endif /* TI_H_ */
