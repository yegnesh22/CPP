/*
 * main.cpp
 *
 *  Created on: Jan 30, 2022
 *      Author: ysiyer
 */

#include <ti.h>
#include <Solutions.h>

vector<ti> t = {
		{
				.m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
				.t = 3,
				.eo = true,
		},
		{
				.m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
				.t = 13,
				.eo = false,
		},
		{
				.m = {{1, 3}},
				.t = 3,
				.eo =  true,
		},
		{
				.m = {{1,1}},
				.t = 0,
				.eo = false,
		},
		{
				.m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}},
				.t = 20,
				.eo = true,
		},
		{
				.m = {{1}},
				.t = 2,
				.eo = false,
		}
};

int main()
{
	Solution* s = new BasicSolution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->searchMatrix(t[i].m, t[i].t);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
