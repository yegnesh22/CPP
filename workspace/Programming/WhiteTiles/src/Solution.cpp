/*
 * Solution.cpp
 *
 *  Created on: Mar 19, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

#define DEBUG

using namespace std;

class Solution {
public:
	int minimumWhiteTiles(string floor, int numCarpets, int carpetLen);
};

int Solution::minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
{
	priority_queue<pair<int,int>> wq;
	int fl = floor.length();
	vector<bool> covered(fl, false);
	int wnC = numCarpets;
	int ll = 0;
	int wl = 0;
	int wc = 0;
	int cl = 0;
	int wT;

	if (fl <= (numCarpets * carpetLen))
		return 0;

	for (int i = 0; i < fl; i++) {
		// black tile
		if (floor[i] == '0') {
#ifdef DEBUG
			cout << "1 -- open length:" << wl << " carpet index:" << ll << endl;
#endif
			if (wl > 0) {
#ifdef DEBUG
				cout << "pushing length:" << wl << " @index:" << ll << endl;
#endif
				wq.push({wl, ll});
			}
			covered[i] = true;
			ll = i+1;
			wl = 0;
		} else {
			wl++;
			wc++;
		}
	}

	if (wl > 0) {
#ifdef DEBUG
		cout << "2 -- open length:" << wl << " carpet:" << ll << endl;
#endif
		wq.push({wl, ll});
	}

	if (wc == 0)
		return wc;

	pair<int, int> top;
	while (numCarpets > 0 && !wq.empty()) {
		int c;

		top = wq.top();
		c = top.first;
#ifdef DEBUG
		cout << "popped length " << c << " @ index " << top.second << endl;
#endif
		wq.pop();
		numCarpets--;
		c = max(c - carpetLen, 0);

		// Set the tiles in between as covered
		int start = top.second;
		int end = min(start + carpetLen, fl);
#ifdef DEBUG
		cout << "covering from " << start << " till " << end - 1 << endl;
#endif
		while (start < end) {
			if (covered[start] == false)
				cl++;
			covered[start] = true;
			start++;
		}

		if (c > 0) {
#ifdef DEBUG
			cout << "pushing back balance length " << c << " from index " << end << endl;
#endif
			wq.push({c, end});
		}
	}

#ifdef DEBUG
	cout << "wc:" << wc << " wnC:" << wnC << " carpetLen:" << carpetLen << endl;
	cout << "returning " << max(wc - cl, 0) << endl;
	while (!wq.empty()) {
		top = wq.top();
		cout << "gap length: " << top.first << " @index: " << top.second << endl;
		wq.pop();
	}
#endif
	return max(wc - cl, 0);
}

#define result(x) ((x.ao == x.eo) ? "pass":"fail")

struct ti {
	string floor;
	int numCarpets;
	int carpetLen;
	int eo;
	int ao;
	ti(string f, int nC, int cL, int e): floor(f), numCarpets(nC), carpetLen(cL), eo(e) {}
};

vector<ti> t = {
#ifndef DEBUG
		ti("11111", 1, 1, 4),
		ti("11111", 2, 3, 0),
		ti("0000", 1, 1, 0),
		ti("0000", 1, 1, 0),
		ti("110000", 1, 1, 1),
		ti("1110111", 2, 1, 4),
		ti("10110101", 2, 2, 2),
		ti("0010000101101001111010010101110001100111000010100011111011100101011000111101001000010011010", 22, 19, 0),
		ti("01111111110111101111001111110111111111101101101111111110111011110111111101101110011110111011001", 72, 1, 3),
		ti("001111110000000011111111010011110100001111000000000111111110000110000000000000001010111111111011110011111111000000010011110000111101111000111101111000111101100111100111100001111001111010000000000000000000100000100000000111100000000001100011111111011111000011111100001000000001111001111111111111011110100001111111101111101111000011110011110001111001111011111111000111100111111111111111100001111000", 68, 4, 0),
#endif
		ti("0001100111110001111111110111010110100111000111111001011011010000011011101100001011111111111111111011110101111011010101001011111111111111111011110101000101010010101111111011011111111101100111111101101111000011101101001110011011100010100111111111111111101011001111101110101110111001111111111110110111111101011110111000111011011010111011111111111111111011111011011111111110001110001100111001101101011111111111111111101011011111101101100111111111111111", 8, 16, 199),
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->minimumWhiteTiles(t[i].floor, t[i].numCarpets, t[i].carpetLen);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
