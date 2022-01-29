/*
 * Solution.h
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <Tree.h>

class Solution {
public:
    virtual vector<vector<int>> levelOrder(TreeNode* root) = 0;
    void printR(vector<vector<int>> r);
};

#endif /* SOLUTION_H_ */
