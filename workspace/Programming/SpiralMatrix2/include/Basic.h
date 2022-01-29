/*
 * Basic.h
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#ifndef BASIC_H_
#define BASIC_H_

#include <Base.h>

class BasicSolution: public Solution {
public:
	typedef enum {
		R = 0,
		D,
		L,
		U,
	} dir;
    vector<vector<int>> generateMatrix(int n);
};

#endif /* BASIC_H_ */
