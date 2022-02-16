/*
 * ti.h
 *
 *  Created on: Feb 16, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<int> n;
	int k;
	int eo;
	int ao;
};

#endif /* TI_H_ */
