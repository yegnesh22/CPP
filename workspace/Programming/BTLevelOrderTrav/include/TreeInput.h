/*
 * TreeInput.h
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#ifndef TREEINPUT_H_
#define TREEINPUT_H_

#include <iostream>
#include <vector>

#include <Tree.h>

using namespace std;

struct ti {
	TreeNode* root;
	vector<vector<int>> eo;
	vector<vector<int>> ao;
};

#endif /* TREEINPUT_H_ */
