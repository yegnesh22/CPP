/*
 * Base.h
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
	virtual bool exist(vector<vector<char>>& board, string word) = 0;
};



#endif /* BASE_H_ */
