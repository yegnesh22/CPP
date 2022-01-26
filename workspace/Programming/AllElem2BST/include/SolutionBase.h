/*
 * Solution.h
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#ifndef SOLUTIONBASE_H_
#define SOLUTIONBASE_H_

#include <Tree.h>

using namespace std;

class Solution {
public:
	virtual vector<int> getAllElements(TreeNode *root1, TreeNode *root2) = 0;
	void printV(vector<int> V);
	vector<int> inorderTraverse(TreeNode *root);
};

#endif /* SOLUTIONBASE_H_ */
