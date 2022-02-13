/*
 * O2.h
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <Base.h>

class Solution: public Base {
private:
	size_t ws;
	string w;
	struct offs {
		int roff;
		int coff;
	};
	vector<offs> offsets = {
			{ .roff = 1, .coff = 0},
			{ .roff = 0, .coff = 1},
			{ .roff = -1, .coff = 0},
			{ .roff = 0, .coff = -1},
	};
	size_t offsize = offsets.size();
	size_t nr;
	size_t nc;
	vector<vector<char>> b;
	vector<vector<bool>> v;
public:
	bool traverse(int r, int c, size_t index);
	bool exist(vector<vector<char>>& board, string word);
};


#endif /* SOLUTION_H_ */
