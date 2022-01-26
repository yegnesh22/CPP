/*
 * OptimalSolution.h
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#ifndef OPTIMALSOLUTION_H_
#define OPTIMALSOLUTION_H_

#include <Tree.h>
#include <SolutionBase.h>

class OptimalSolution: public Solution {
private:
	vector<int> mergeV(vector<int> v1, vector<int> v2);
public:
	vector<int> getAllElements(TreeNode *root1, TreeNode *root2);
};

#endif /* OPTIMALSOLUTION_H_ */
