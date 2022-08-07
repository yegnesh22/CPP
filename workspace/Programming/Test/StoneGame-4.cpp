/*
 * Solution.cpp
 *
 *  Created on: Jan 22, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Solution {
public:
    virtual bool winnerSquareGame(int n) = 0;
};

// Logic - If there exists a state such that opponent can win
// the game, it means that the current player can lose the
// game.

class Basic: public Solution {
public:
	Basic() {
		cout << "Basic Solution --- " << endl;
	}
	bool canWin(int n) {
		int s = sqrt(n);

		if (n == 0)
			return false;
		if (n == 1)
			return true;

		for (int i = 1; i <= s; i++) {
			if (!canWin(n - (i * i)))
				return true;
		}

		return false;
	}

	bool winnerSquareGame(int n)
	{
		return canWin(n);
	}
};

class BasicWithLookup: public Solution {
public:
	BasicWithLookup() {
		cout << "Solution with lookup --- " << endl;
	}

	bool canWin(map<int, bool>& lookup, int n) {
		if (lookup.find(n) != lookup.end())
			return lookup[n];

		int s = sqrt(n);

		for (int i = 1; i <= s; i++) {
			if (!canWin(lookup, (n - (i * i)))) {
				lookup.insert(pair<int, bool>(n, true));
				return true;
			}
		}

		lookup.insert(pair<int, bool>(n, false));
		return false;
	}

	bool winnerSquareGame(int n)
	{
		map<int, bool> lookup;

		lookup.insert(pair<int, bool>(0, false));
		lookup.insert(pair<int, bool>(1, true));

		return canWin(lookup, n);
	}
};

struct TI {
	int i;
	bool eo;
	bool ao;
};

int main()
{
	vector<TI> t = {
			{.i = 1, .eo = true},
			{.i = 2, .eo = false},
			{.i = 4, .eo = true},
			{.i = 8, .eo = true},
			{.i = 99, .eo = true},
			{.i = 92719, .eo = true},
	};

	Solution *s = new Basic();

	for(int i = 0; i < 4; i++) {
		t[i].ao = s->winnerSquareGame(t[i].i);
		cout << "t[" << i << "] -- eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass":"fail")
				<< endl;
	}
	delete s;

	s = new BasicWithLookup();

	for(int i = 4; i < t.size(); i++) {
		t[i].ao = s->winnerSquareGame(t[i].i);
		cout << "t[" << i << "] -- eo = " << t[i].eo
				<< " ao = " << t[i].ao
				<< " result = " << ((t[i].ao == t[i].eo) ? "pass":"fail")
				<< endl;
	}
	delete s;

	return 0;
}
