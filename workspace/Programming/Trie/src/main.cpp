/*
 * main.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <Trie.h>
#include <TI.h>

vector<ti> t = {
		{
				.ins = {"app", "apple", "beer", "add", "jam", "rental"},
				.s = {"apps","app","ad","applepie","rest","jan","rent","beer","jam"},
				.sp = {"apps","app","ad","applepie","rest","jan","rent","beer","jam"},
				.eo = {false,true,false,false,false,false,false,true,true,false,true,true,false,false,false,true,true,true}
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
		Trie *tr = new Trie();
		for (int j = 0; j < t[i].ins.size(); j++) {
			tr->insert(t[i].ins[j]);
		}

		for (int j = 0; j < t[i].s.size(); j++) {
			t[i].ao.push_back(tr->search(t[i].s[j]));
		}

		for (int j = 0; j < t[i].sp.size(); j++) {
			t[i].ao.push_back(tr->startsWith(t[i].sp[j]));
		}

		printV(t[i].eo);
		printV(t[i].ao);

		cout << i << " -- " << ((t[i].ao == t[i].eo) ? "pass" : "fail") << endl;
	}
}
