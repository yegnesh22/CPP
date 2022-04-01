/*
 * ti.h
 *
 *  Created on: Mar 12, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	string p;
	int eo;
	int ao;
	ti(string pa, int e): p(pa), eo(e) {}
};

#endif /* TI_H_ */
