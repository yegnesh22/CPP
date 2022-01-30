/*
 * main.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <BasicSolution.h>

vector<ti> t = {
		{
				.nums = {1,2,3,4,5,6,7},
				.k = 3,
				.eo = {5,6,7,1,2,3,4},
		},
		{
				.nums = {-1,-100,3,99},
				.k = 2,
				.eo = {3,99,-1,-100},
		},
};

int main()
{
	Solution* s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		s->rotate(t[i].nums, t[i].k);
		cout << i << " -- " << check_result(t[i]) << endl;
	}
	return 0;
}
