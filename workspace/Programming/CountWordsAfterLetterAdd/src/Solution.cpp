/*
 * Solution.cpp
 *
 *  Created on: Feb 19, 2022
 *      Author: ysiyer
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Algorithm: Take every word in targetWords, create all combos by removing
 * 1 letter from it.
 * Lookup for the combinations in the startWords.
 * If even 1 word combination is present, the targetWord can be added.
 * If none of the combinations exist, the targetWord cannot be added.
 *
 */

//#define DEBUG

struct TrieNode {
	TrieNode* alphabets[26] = {nullptr};
	bool word = false;
};

class Solution {
private:
	TrieNode* swT;
	void insert(string w);
public:
	void genW(string w, vector<string>& c);
	bool canAdd(string w);
	int wordCount(vector<string>& startWords, vector<string>& targetWords);
};

void Solution::insert(string w)
{
	int wl = w.length();
	TrieNode* t = swT;
	int ci;

	for (int i = 0; i < w.length(); i++) {
		ci = w[i] - 'a';
		if (t->alphabets[ci] == nullptr)
			t->alphabets[ci] = new TrieNode();
		t = t->alphabets[ci];
	}
	t->word = true;
}

void Solution::genW(string w, vector<string>& c)
{
	int ws = w.size();
	string wc;

	for (int i  = ws - 1; i >= 0; i--) {
		wc = w;
		wc.erase(wc.begin() + i);
		c.push_back(wc);
	}
}

bool Solution::canAdd(string w)
{
	vector<string> combos;
	int wl = w.length();
	TrieNode* t= swT;
	bool found;
	int ci;
	int cs;

	genW(w, combos);
	cs = combos.size();
	for (int i = 0; i < cs; i++) {
		t = swT;
		found = true;
		for (int j = 0; j < combos[i].length(); j++) {
			ci = combos[i][j] - 'a';
			if (t->alphabets[ci] == nullptr) {
				found = false;
				break;
			}
			t = t->alphabets[ci];
		}
		if (found && t->word) {
			return true;
		}
	}

	return false;
}

int Solution::wordCount(vector<string>& startWords, vector<string>& targetWords)
{
	int sws = startWords.size();
	int tws = targetWords.size();

	swT = new TrieNode();
	for (int i = 0; i < sws; i++) {
		sort(startWords[i].begin(), startWords[i].end());
		insert(startWords[i]);
	}

	int count = 0;
	for (int i = 0; i < tws; i++) {
		sort(targetWords[i].begin(), targetWords[i].end());
		if (canAdd(targetWords[i]))
			count++;
	}

	return count;
}

#define result(x) ((x.ao == x.eo) ? "pass" : "fail")

struct ti {
	vector<string> s;
	vector<string> t;
	int eo;
	int ao;
};

vector<ti> t = {
		{
				.s = {"ant","act","tack"},
				.t = {"tack","act","acti"},
				.eo = 2,
		},
		{
				.s = {"ab","a"},
				.t = {"abc","abcd"},
				.eo = 1,
		},
		{
				.s = {"r","axogl","nu","vudsc","ms","i","jr"},
				.t = {"ybice","hrexd","rn","fjp","tnvru","px","iy","f"},
				.eo = 2,
		},
		{
				.s  = {"r", "i"},
				.t = {"rn", "iy"},
				.eo = 2,
		},
};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->wordCount(t[i].s, t[i].t);
		cout << i << " -- " << result(t[i]) << endl;
	}

	return 0;
}
