/*
 * Base.h
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#ifndef BASE_H_
#define BASE_H_

#include <iostream>
#include <vector>
#include <Tree.h>

using namespace std;

class Solution {
public:
    virtual TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) = 0;
    vector<int> buildVector(TreeNode* r);
};


#endif /* BASE_H_ */
