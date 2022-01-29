/*
 * Solution.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <Trie.h>

Trie::Trie()
{
	m_root = new TrieNode();
}

int Trie::getIndex(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else
		return -1;
}

void Trie::insert(string word)
{
	TrieNode* t = m_root;
	int index;

	for (int i = 0; i < word.size(); i++) {
		index = getIndex(word[i]);
		if (t->c[index] == nullptr) {
			t->c[index] = new TrieNode();
		}
		t = t->c[index];
	}
	cout << "Insert " << word << " setting " << (char)(index + 'a') << " eow as true" << endl;
	t->eow = true;

	return;
}

bool Trie::search(string word)
{
	TrieNode* t = m_root;
    int index;

	for (int i = 0; i < word.size(); i++) {
		index = getIndex(word[i]);
		cout << "searching " << word[i] << endl;
		if (index == -1) {
			cout << "F: " << __func__ << " L: " << __LINE__  << " return false"<< endl;
			return false;
		}
		if (t->c[index] == nullptr) {
			cout << "F: " << __func__ << " L: " << __LINE__  << " return false"<< endl;
			return false;
		}
		t = t->c[index];
	}
	cout << "F: " << __func__ << " L: " << __LINE__ << " return " << (t->eow ? "true" : "false") << endl;
	return t->eow;
}

bool Trie::startsWith(string prefix)
{
	TrieNode* t = m_root;
    int index;

	for (int i = 0; i < prefix.size(); i++) {
		if (prefix[i] == '*')
			return true;
		index = getIndex(prefix[i]);
		if (index == -1)
			return false;
		if (t->c[index] == nullptr)
			return false;
		t = t->c[index];
	}

	return true;
}
