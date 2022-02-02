/*
 * Solution.cpp
 *
 *  Created on: 01-Feb-2022
 *      Author: yegnesh
 */

#include <iostream>
#include <vector>

using namespace std;

#define check_result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<vector<char>> i;
	bool eo;
	bool ao;
};


class Solution {
public:
    virtual bool isValidSudoku(vector<vector<char>>& board) = 0;
};

class Basic: public Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board);
};

bool Basic::isValidSudoku(vector<vector<char>>& board)
{
	vector<vector<bool>>rlookup(9, vector<bool>(9, false));
	vector<vector<bool>>clookup(9, vector<bool>(9, false));
	vector<vector<bool>>glookup(9, vector<bool>(9, false));
	int gindex;
	char val;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] != '.') {

				// Check row lookup
				val = board[i][j] -  '1';

				if (!rlookup[i][val])
					rlookup[i][val] = true;
				else
					return false;

				// Check column lookup
				if (!clookup[j][val])
					clookup[j][val] = true;
				else
					return false;

				// Check the grid lookup
				gindex = 3 * (i / 3) + j / 3;
				if(!glookup[gindex][val])
					glookup[gindex][val] = true;
				else
					return false;
			}
		}
	}

	return true;
}


vector<ti> t = {
		{
				.i = {
						{'5','3','.','.','7','.','.','.','.'},
						{'6','.','.','1','9','5','.','.','.'},
						{'.','9','8','.','.','.','.','6','.'},
						{'8','.','.','.','6','.','.','.','3'},
						{'4','.','.','8','.','3','.','.','1'},
						{'7','.','.','.','2','.','.','.','6'},
						{'.','6','.','.','.','.','2','8','.'},
						{'.','.','.','4','1','9','.','.','5'},
						{'.','.','.','.','8','.','.','7','9'},
				},
				.eo = true,
		},
		{
				.i = {
						{'8','3','.','.','7','.','.','.','.'},
						{'6','.','.','1','9','5','.','.','.'},
						{'.','9','8','.','.','.','.','6','.'},
						{'8','.','.','.','6','.','.','.','3'},
						{'4','.','.','8','.','3','.','.','1'},
						{'7','.','.','.','2','.','.','.','6'},
						{'.','6','.','.','.','.','2','8','.'},
						{'.','.','.','4','1','9','.','.','5'},
						{'.','.','.','.','8','.','.','7','9'},
				},
				.eo = false,
		},
		{
				.i = {
						{'7','.','.','.','4','.','.','.','.'},
						{'.','.','.','8','6','5','.','.','.'},
						{'.','1','.','2','.','.','.','.','.'},
						{'.','.','.','.','.','9','.','.','.'},
						{'.','.','.','.','5','.','5','.','.'},
						{'.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','2','.','.'},
						{'.','.','.','.','.','.','.','.','.'},
						{'.','.','.','.','.','.','.','.','.'},
				},
				.eo = false,
		},
};

int main()
{
	Solution *s = new Basic();

	for(int i = 0; i < t.size(); i++) {
		t[i].ao = s->isValidSudoku(t[i].i);
		cout << i << " -- " << check_result(t[i]) << endl;
	}

	return 0;
}
