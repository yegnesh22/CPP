/*
 * ti.h
 *
 *  Created on: Feb 8, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	int t;
	vector<int> p;
	vector<int> s;
	int ao;
	int eo;
};



#endif /* TI_H_ */
