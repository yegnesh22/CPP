/*
 * ti.h
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define result(x) ((x.ao == x.eo) ? "pass": "fail")

struct ti {
	vector<vector<char>> b;
	string w;
	bool eo;
	bool ao;
};

#endif /* TI_H_ */
