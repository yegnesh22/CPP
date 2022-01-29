/*
 * Trie.h
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#ifndef TRIE_H_
#define TRIE_H_

#include <iostream>
#include <vector>

using namespace std;

#define NUM_ALPHABETS 26

struct TrieNode {
	TrieNode* c[NUM_ALPHABETS] = {nullptr};
	bool eow = false;
};

class Trie {
private:
	TrieNode* m_root;
public:
    Trie();
    int getIndex(char c);
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
};

#endif /* TRIE_H_ */
