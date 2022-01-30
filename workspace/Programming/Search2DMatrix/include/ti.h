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

#define check_result(x) ((x.eo == x.ao) ? "pass" : "fail")

struct ti {
	vector<vector<int>> m;
	int t;
	bool eo;
	bool ao;
};

#endif /* TI_H_ */
