/*
 * Solution.cpp
 *
 *  Created on: Feb 28, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define SPACE 0
#define NUM_ALPHABETS 26
#define NUM_CHARS (NUM_ALPHABETS + 1)

struct Trie {
	Trie* n[NUM_CHARS] = {nullptr};
	string f;
	bool eos = false;
	int occurence = 0;
	bool operator() (Trie* const& w1, Trie* const& w2) {
			if (w1->occurence == w2->occurence)
				return w1->f > w2->f;
			return w1->occurence < w2->occurence;
	}
};

typedef priority_queue<Trie*, vector<Trie*>, Trie> TrieQ;

class AutocompleteSystem {
private:
	Trie* root;
	Trie* m_t;
	string m_s;
public:
	AutocompleteSystem(vector<string>& sentences, vector<int>& times);
	vector<string> input(char c);
	void findAllWords(Trie* t, TrieQ& wq);
};

AutocompleteSystem::AutocompleteSystem(vector<string>& sentences, vector<int>& times)
{
	int ne = sentences.size();
	root = new Trie();
	int index;
	Trie* t;
	char ch;
	int sl;

	for (int i = 0; i < ne; i++) {
		sl = sentences[i].length();
		t = root;
		for (int j = 0; j < sl; j++) {
			ch = sentences[i][j];
			if (ch == ' ')
				index = SPACE;
			else
				index = ch - 'a' + 1;

			if (t->n[index] == nullptr)
				t->n[index] = new Trie();
			t = t->n[index];
		}
		t->f = sentences[i];
		t->eos = true;
		t->occurence = times[i];
	}
	m_t = root;
}

vector<string> AutocompleteSystem::input(char c)
{
	vector<string> result;
	int index;
	TrieQ wq;

	if (c == '#') {
		m_t->occurence++;
		m_t->eos = true;
		m_t->f = m_s;
		m_s.clear();
		m_t = root;
	}
	else {
		m_s += c;
		if (c == ' ')
			index = SPACE;
		else
			index = c - 'a' + 1;
		if (m_t->n[index] == nullptr)
			m_t->n[index] = new Trie();

		m_t = m_t->n[index];

		findAllWords(m_t, wq);
	}

	int i = 0;
	while (!wq.empty() && (i < 3)) {
		result.push_back(wq.top()->f);
		wq.pop();
		i++;
	}
	return result;
}

void AutocompleteSystem::findAllWords(Trie* t, TrieQ& wq)
{
	if (t == nullptr)
		return;

	if (t->eos)
		wq.push(t);

	for (int i = 0; i < NUM_CHARS; i++) {
		if (t->n[i] != nullptr) {
			findAllWords(t->n[i], wq);
		}
	}

	return;
}

void printV(vector<string> v)
{
	cout << "-----------------------" << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << "-----------------------" << endl;
}

int main()
{
	vector<string> sentences = {"i love you", "island", "iroman", "i love leetcode"};
	vector<int> times = {5, 3, 2, 2};
	AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);

	cout << "First input" << endl;
	printV(obj->input('i'));
	printV(obj->input(' '));
	printV(obj->input('a'));
	printV(obj->input('#'));
	cout << "Second input" << endl;
	printV(obj->input('i'));
	printV(obj->input(' '));
	printV(obj->input('a'));
	printV(obj->input('#'));
	cout << "Third input" << endl;
	printV(obj->input('i'));
	printV(obj->input(' '));
	printV(obj->input('a'));
	printV(obj->input('#'));

	return 0;
}
