/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* traverse(TreeNode* t, vector<int>& v) {
        if (t->left == nullptr && t->right == nullptr) {
            v.push_back(t->val);
            return nullptr;
        }
        
        if (t->left !=  nullptr)
            t->left = traverse(t->left, v);
        if (t->right != nullptr)
            t->right = traverse(t->right, v);
        
        return t;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> r;
        TreeNode* t = root;
        
        while (t != nullptr) {
            vector<int> v;
            t = traverse(t, v);
            r.push_back(v);
        }
        return r;
    }
};


