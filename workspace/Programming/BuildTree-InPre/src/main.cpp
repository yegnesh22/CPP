/*
 * main.cpp
 *
 *  Created on: Jan 31, 2022
 *      Author: ysiyer
 */

#include <Base.h>
#include <Basic.h>
#include <ti.h>

vector<ti> t ={
		{
				.pre = {3,9,20,15,7},
				.in = {9,3,15,20,7},
				.eo = {9,15,7,20,3},
		},
		{
				.pre = {-1},
				.in = {-1},
				.eo = {-1},
		}
};

int main()
{
	Solution *s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].root = s->buildTree(t[i].pre, t[i].in);
		t[i].po = s->buildVector(t[i].root);
		cout << i << " -- " << check_result(t[i]) << endl;
	}
	return 0;
}
