/*
 * main.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <wd.h>
#include <ti.h>

vector<ti> t = {
		{
				.ins = {"bad","dad","mad"},
				.s  = {"pad","bad",".ad","b.."},
				.eo = {false,true,true,true},
		},
};

void printV(vector<bool> v)
{
	for (int i  = 0; i < v.size(); i++)
		cout << (v[i] ? "true " : "false ") << flush;

	cout << endl;
}

int main()
{
	for (int i = 0; i < t.size(); i++) {
		WordDictionary *wd = new WordDictionary();
		for (int j = 0; j < t[i].ins.size(); j++) {
			wd->addWord(t[i].ins[j]);
		}

		for (int j = 0; j < t[i].s.size(); j++) {
			t[i].ao.push_back(wd->search(t[i].s[j]));
		}

		printV(t[i].eo);
		printV(t[i].ao);

		cout << i << " -- " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}
}
