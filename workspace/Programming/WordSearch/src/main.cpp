/*
 * main.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#include <Solution.h>
#include <ti.h>

vector<ti> t = {
		{
				.b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
				.w = "ABCCED",
				.eo = true,
		},
		{
				.b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
				.w = "SEE",
				.eo = true,
		},

		{
				.b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}},
				.w = "ABCB",
				.eo = false,
		},
		{
				.b = {{'a','b'},{'c','d'}},
				.w = "abcd",
				.eo = false,
		},
		{
				.b = {
						{'A','A','A','A','A','A'},
						{'A','A','A','A','A','A'},
						{'A','A','A','A','A','A'},
						{'A','A','A','A','A','A'},
						{'A','A','A','A','A','A'},
						{'A','A','A','A','A','A'},
				},
				.w = "AAAAAAAAAAAAAAB",
				.eo = false,
		},
};

int main()
{
	for (size_t i = 0; i < t.size(); i++) {
		Base* s = new Solution();
		t[i].ao = s->exist(t[i].b, t[i].w);
		cout << i << " -- " << result(t[i]) << endl;
		delete s;
	}
	return 0;
}
