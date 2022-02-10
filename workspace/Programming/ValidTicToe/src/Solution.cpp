/*
 * Solution.cpp
 *
 *  Created on: Feb 9, 2022
 *      Author: ysiyer
 */

#include <Solution.h>

/*
+----+-----+-----+
|  1 |  2  |  4  |
+----+-----+-----+
|  8 | 16  | 32  |
+----+-----+-----+
| 64 | 128 | 256 |
+----+-----+-----+
*/

bool Solution::check(int s, vector<int> w)
{
	int ws = w.size();
	for (int i  = 0; i < ws; i++) {
		if ((s & w[i]) == w[i])
			return true;
	}
	return false;
}

bool Solution::validTicTacToe(vector<string>& board)
{
	vector<int> winL {7, 56, 73, 84, 146, 273, 292, 448}; // obtained by summing up the cell values
	int nc = board[0].size();
	int nr = board.size();
	map<char, int> index;
	vector<int> c(3, 0);
	vector<int> s(3, 0);

	index.insert(pair<char, int>('O', 0));
	index.insert(pair<char, int>('X', 1));
	index.insert(pair<char, int>(' ', 2));

	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			c[index[board[i][j]]]++;
			s[index[board[i][j]]] += 1 << (i * 3 + j);
		}
	}

	if (c[index['O']] > c[index['X']]) // Invalid state because first player always plays X.
		return false;

	int diff  = abs(c[index['O']] - c[index['X']]);
	if (diff > 1) // Invalid state because players take states
		return false;

	bool xWins = check(s[index['X']], winL);
	bool oWins = check(s[index['O']], winL);

	cout << "xwins: " << xWins << " owins:" << oWins << endl;
	if (xWins) {
		if (oWins || (diff == 0) || (diff != 1))
			return false;
	}

	if (oWins) {
		if (diff != 0)
			return false;
	}
	return true;
}
