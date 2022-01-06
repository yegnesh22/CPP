/*
 * Solution.cpp
 *
 *  Created on: 31-Dec-2021
 *      Author: yegnesh
 */


// Definition for a binary tree node.

#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void printV(vector<int> a) {
        cout << "( ";
        for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
            cout << *it << " " << flush;
        cout << " )" << endl;
    }
	vector<int> FindMinMax(TreeNode* Node) {
		vector<int> v;
		vector<int> result;

		if (Node->left == nullptr && Node->right == nullptr) {
			// Leaf
			v.push_back(Node->val);
			v.push_back(Node->val);
            printV(v);
			return v;
		}

		if (Node->right != nullptr) {
			vector<int> r = FindMinMax(Node->right);
			v.insert(v.end(), r.begin(), r.end());
		}

		if (Node->left != nullptr) {
			vector<int> l = FindMinMax(Node->left);
			v.insert(v.end(), l.begin(), l.end());
		}

		v.push_back(Node->val);

		result.push_back(min_element(v.begin(), v.end()));
		result.push_back(max_element(v.begin(), v.end()));
        printV(result);
		return result;
	}

    int maxAncestorDiff(TreeNode* root) {
    	TreeNode* node = root;

    	vector<int> l = FindMinMax(root->left);
    	vector<int> r = FindMinMax(root->right);

    	l.push_back(root->val);
    	r.push_back(root->val);

    	int ldiff = max_element(l.begin(), l.end()) - min_element(l.begin(), l.end());
    	int rdiff = max_element(r.begin(), r.end()) - min_element(r.begin(), r.end());

    	int max = ldiff > rdiff ? ldiff : rdiff;
    	return max;
    }
};


