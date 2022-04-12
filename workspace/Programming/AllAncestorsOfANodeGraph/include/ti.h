/*
 * ti.h
 *
 *  Created on: Apr 7, 2022
 *      Author: ysiyer
 */

#ifndef INCLUDE_TI_H_
#define INCLUDE_TI_H_

#include <iostream>
#include <cassert>
#include <bitset>
#include <vector>
#include <queue>

using namespace std;

//#define DEBUG

struct ti {
	int n;
	vector<vector<int>> edges;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
	ti(int tn, vector<vector<int>> te, vector<vector<int>> teo): n(tn), edges(te), eo(teo) {}
};

#endif /* INCLUDE_TI_H_ */
