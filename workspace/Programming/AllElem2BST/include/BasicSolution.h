/*
 * BasicSolution.h
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#ifndef BASICSOLUTION_H_
#define BASICSOLUTION_H_

#include <iostream>
#include <vector>

#include <SolutionBase.h>

using namespace std;

class BasicSolution: public Solution {
private:
	TreeNode* mergeTree(TreeNode *root1, TreeNode *root2);
public:
	vector<int> getAllElements(TreeNode *root1, TreeNode *root2);
};

#endif /* BASICSOLUTION_H_ */
