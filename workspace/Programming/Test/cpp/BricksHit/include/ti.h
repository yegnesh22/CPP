/*
 * ti.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#ifndef INCLUDE_TI_H_
#define INCLUDE_TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<int>> g;
	vector<vector<int>> h;
	vector<int> eo;
	vector<int> ao;
};

#endif /* INCLUDE_TI_H_ */
