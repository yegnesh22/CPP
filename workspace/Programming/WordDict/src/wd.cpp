/*
 * wd.cpp
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#include <wd.h>

WordDictionary::WordDictionary()
{
	m_root = new WordNode();
}

int WordDictionary::getIndex(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else if (c == '.')
		return 26;
	else
		return -1;
}

void WordDictionary::addWord(string word)
{
	WordNode* t = m_root;
	WordNode* p;
	int index;

	for (int i = 0; i < word.size(); i++) {
		index = getIndex(word[i]);
		if (t->c[index] == nullptr) {
			t->c[index] = new WordNode();
		}
		t = t->c[index];
	}
	t->eow = true;

	return;
}

/*
 * Search in Trie
 * In the absence of '.' characters, the search would be as simple as addWord.
 * Each key is represented in the trie as a path from the root to the internal
 * node or leaf. We start from the root and go down in trie, checking character
 * by character.
 * The presence of '.' characters forces us to explore all possible paths at
 * each . level.
 */


bool WordDictionary::searchNode(string word, WordNode* t)
{
    int index;

	for (int i = 0; i < word.size(); i++) {
		index = getIndex(word[i]);
		if (index == -1) {
			return false;
		}
		if (t->c[index] == nullptr) {
			if (word[i] == '.') {
				// Presence of . character proceed down all the possible
				// paths.
				for (int k = 0; k < (NUM_ALPHABETS - 1); k++) {
					if (t->c[k] != nullptr) {
						if (searchNode(word.substr(i+1, word.length() - i - 1), t->c[k]))
								return true;
					}
				}
			}
			return false;
		}
		t = t->c[index];
	}

	return t->eow;
}

bool WordDictionary::search(string word)
{
	return searchNode(word, m_root);
}
