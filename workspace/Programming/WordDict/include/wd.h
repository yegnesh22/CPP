/*
 * wd.h
 *
 *  Created on: Jan 28, 2022
 *      Author: ysiyer
 */

#ifndef WD_H_
#define WD_H_


#include <iostream>
#include <vector>

using namespace std;

#define NUM_ALPHABETS 27

struct WordNode {
	WordNode* c[NUM_ALPHABETS] = {nullptr};
	bool eow = false;
};

class WordDictionary {
private:
	WordNode* m_root;
public:
    WordDictionary();
    int getIndex(char c);
    void addWord(string word);
    bool searchNode(string word, WordNode* t);
    bool search(string word);
};



#endif /* WD_H_ */
