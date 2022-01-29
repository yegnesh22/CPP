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
	vector<vector<int>> i;
	vector<int> eo;
	vector<int> ao;
};

#endif /* TI_H_ */
