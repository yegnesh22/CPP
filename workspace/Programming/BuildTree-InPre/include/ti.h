/*
 * ti.h
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#ifndef TI_H_
#define TI_H_

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.eo == x.po) ? "pass" : "fail")

struct ti {
	vector<int> pre;
	vector<int> in;
	vector<int> po;
	vector<int> eo;
	TreeNode* root;
};

#endif /* TI_H_ */
