/*
 * OptimalSolution.cpp
 *
 *  Created on: Jan 26, 2022
 *      Author: ysiyer
 */

#include <OptimalSolution.h>

vector<int> OptimalSolution::mergeV(vector<int> v1, vector<int> v2)
{
	int s1 = v1.size();
	int s2 = v2.size();
	vector<int> r;
	int i = 0, j = 0;

	while (i < s1 && j < s2) {
		if (v1[i] < v2[j]) {
			r.push_back(v1[i]);
			i++;
		} else {
			r.push_back(v2[j]);
			j++;
		}
	}

	while (i < s1) {
		r.push_back(v1[i]);
		i++;
	}

	while (j < s2) {
		r.push_back(v2[j]);
		j++;
	}

	return r;
}

vector<int> OptimalSolution::getAllElements(TreeNode *root1, TreeNode *root2)
{
	vector<int> t1;
	vector<int> t2;

	cout << "Traverse Trees and mergesort the results method!!" << endl;
	t1 = inorderTraverse(root1);
	t2 = inorderTraverse(root2);

	return mergeV(t1, t2);
}
