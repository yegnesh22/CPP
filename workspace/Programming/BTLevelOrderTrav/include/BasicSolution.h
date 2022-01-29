/*
 * BasicSolution.h
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */

#ifndef BASICSOLUTION_H_
#define BASICSOLUTION_H_

#include <Solution.h>

class BasicSolution: public Solution {
private:
	vector<vector<int>> BreadthFirstTraverse(queue<TreeNode*> nl);
public:
	vector<vector<int>> levelOrder(TreeNode* root);
};


#endif /* BASICSOLUTION_H_ */
