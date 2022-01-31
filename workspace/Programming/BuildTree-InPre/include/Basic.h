/*
 * Basic.h
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#include <Base.h>

class BasicSolution : public Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
    TreeNode* constructTree(vector<int>& po, vector<int>& io,
    						int& ri, int s, int e);
};
