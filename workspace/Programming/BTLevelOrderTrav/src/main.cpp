/*
 * main.cpp
 *
 *  Created on: Jan 27, 2022
 *      Author: ysiyer
 */


#include <Tree.h>
#include <Solution.h>
#include <BasicSolution.h>
#include <TreeInput.h>

vector<ti> v = {
		{
				.root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))),
				.eo = {{3},{9,20},{15,7}},
		},
		{
				.root = new TreeNode(1),
				.eo = {{1}},
		},
		{
				.root = nullptr,
				.eo = {},
		},
};

int main()
{
	Solution *s = new BasicSolution();
	for (int i = 0; i < v.size(); i++) {
		v[i].ao = s->levelOrder(v[i].root);
		s->printR(v[i].ao);
		cout << i << " -- r = " << ((v[i].ao == v[i].eo) ? "pass" : "fail") << endl;
	}

	return 0;
}
