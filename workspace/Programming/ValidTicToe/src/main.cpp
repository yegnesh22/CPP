/*
 * main.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: ysiyer
 */

#include <Solution.h>
#include <ti.h>

vector<ti> t = {
		{
				.b = {"O  ","   ","   "},
				.eo = false,
		},
		{
				.b = {"XOX"," X ","   "},
				.eo = false,
		},
		{
				.b = {"XOX","O O","XOX"},
				.eo = true,
		},
		{
				.b = {"XXX","   ","OOO"},
				.eo = false,
		},
		{
				.b = {"XXX","XOO","OO "},
				.eo = false,
		},
		{
				.b = {"XXX","OOX","OOX"},
				.eo = true,
		},
};

int main()
{
	Solution* s = new Solution();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->validTicTacToe(t[i].b);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
