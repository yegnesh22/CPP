/*
 * O1.h
 *
 *  Created on: Jan 29, 2022
 *      Author: ysiyer
 */

#ifndef O1_H_
#define O1_H_


#include <SolutionBase.h>

class O1: public Solution {
private:
	int calcArea(vector<int>& h, int start, int end);
public:
    int largestRectangleArea(vector<int>& heights);
};

#endif /* O1_H_ */
