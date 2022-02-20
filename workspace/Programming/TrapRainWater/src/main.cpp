/*
 * main.cpp
 *
 *  Created on: Feb 3, 2022
 *      Author: ysiyer
 */

#include <Base.h>
#include <Basic.h>
#include <ti.h>

vector<ti> t = {
		{
				.i = {0,1,0,2,1,0,1,3,2,1,2,1},
				.eo = 6,
		},
		{
				.i = {4,2,0,3,2,5},
				.eo = 9,
		},
};

int main()
{
	Solution* s = new Basic();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->trap(t[i].i);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
