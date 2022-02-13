/*
 * O2.cpp
 *
 *  Created on: Feb 13, 2022
 *      Author: ysiyer
 */

#include <Solution.h>

bool Solution::traverse(int r, int c, size_t index)
{
	size_t nxtr;
	size_t nxtc;

	if (index == ws-1) // All letters found.
		return true;

	for (size_t i = 0; i < offsize; i++) {
		nxtr = r + offsets[i].roff;
		nxtc = c + offsets[i].coff;

		if ((nxtr < nr) && (nxtc < nc) && (b[nxtr][nxtc] == w[index+1])) {
			if (v[nxtr][nxtc] == false) {
				v[nxtr][nxtc] = true;
				if (traverse(nxtr, nxtc, index+1))
					return true;
				else
					v[nxtr][nxtc] = false;
			}
		}
	}
	return false;
}

bool Solution::exist(vector<vector<char>>& board, string word)
{
	ws = word.size();
	nr = board.size();
	nc = board[0].size();
	w = word;
	b = board;
	v = vector<vector<bool>> (nr, vector<bool> (nc,false));

	for(size_t i = 0; i < nr; i++) {
		for(size_t j = 0; j < nc; j++) {
			if (b[i][j] == w[0]) {
				v[i][j] = true;
				if (traverse(i, j, 0))
					return true;
				else
					v[i][j] = false;
			}
		}
	}

	return false;
}
