/*
 * Solution.cpp
 *
 *  Created on: Apr 1, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
private:
	string m_punct_str = ".";
	vector<string> m_MALPHA = {
			".-", // a
			"-...", // b
			"-.-.", // c
			"-..", // d
			".", // e
			"..-.", // f
			"--.", // g
			"....", // h
			"..",  // i
			".---",  // j
			"-.-",  // k
			".-..",  // l
			"--",  // m
			"-.", // n
			"---",  // o
			".--.",  // p
			"--.-",  // q
			".-.",  // r
			"...",  // s
			"-",  // t
			"..-",  // u
			"...-",  // v
			".--",  // w
			"-..-",  // x
			"-.--",  // y
			"--..",  // z
	};
	vector<string> m_MNUM = {
			"-----",
			".----",
			"..---",
			"...--",
			"....-",
			".....",
			"-....",
			"--...",
			"---..",
			"----."
	};
	vector<string> m_MPUNCT = {
			".-.-.-",
	};
public:
	bool isUpper(char c);
	bool isLower(char c);
	bool isNum(char c);
	bool isPunct(char c);
	int findPunctIndex(char c);
	string run(bool morseToEnglish, string textToTranslate);
	bool getChar(string m, char& c);
};

bool Solution::isUpper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

bool Solution::isLower(char c)
{
	return (c >= 'a' && c <= 'z');
}

bool Solution::isNum(char c)
{
	return (c >= '0' && c <= '9');
}

bool Solution::isPunct(char c)
{
	return m_punct_str.find(c) != m_punct_str.npos;
}

int Solution::findPunctIndex(char c)
{
	for (int i = 0; i < m_punct_str.length(); i++) {
		if (c == m_punct_str[i])
			return i;
	}
	return -1;
}

bool Solution::getChar(string m, char& c)
{
	cout << "input:" << m << endl;
	for (int i = 0; i < m_MALPHA.size(); i++) {
		if (m == m_MALPHA[i]) {
			c = 'A' + i;
			cout << "returning " << c << endl;
			return true;
		}
	}
	for (int i = 0; i < m_MNUM.size(); i++) {
		if (m == m_MNUM[i]) {
			c = '0' + i;
			cout << "returning " << c << endl;
			return true;
		}
	}
	for (int i = 0; i < m_MPUNCT.size(); i++) {
		if (m == m_MPUNCT[i]) {
			c = m_punct_str[i];
			cout << "returning " << c << endl;
			return true;
		}
	}

	return false;
}

string Solution::run(bool morseToEnglish, string textToTranslate)
{
	int ts = textToTranslate.length();
	string result;
	int lasti;
	int index;
	char c;

	if (morseToEnglish == false) {
		for (int i  = 0; i < ts; i++) {
			char c = textToTranslate[i];
			string cur;
			if (isUpper(c)) {
				index = textToTranslate[i] - 'A';
				cur.append(m_MALPHA[index]);
			} else if (isLower(c)) {
				index = textToTranslate[i] - 'a';
				cur.append(m_MALPHA[index]);
			} else if (isNum(c)) {
				index = textToTranslate[i] - '0';
				cur.append(m_MNUM[index]);
			} else if (c == ' ') {
				cur.append(" ");
			} else if (isPunct(c)) {
				index = findPunctIndex(c);
				cur.append(m_MPUNCT[index]);
			}
			if (i != ts - 1)
				cur.append(" ");
			result.append(cur.begin(), cur.end());
		}
	} else {
		lasti = 0;
		for (int i = 0; i < ts; i++) {
			if (textToTranslate[i] == ' ') {
				string s = textToTranslate.substr(lasti, i - lasti);
				lasti = i + 1;
				if (getChar(s, c))
					result.push_back(c);
				else
					return "Invalid MorseCode or spacing";
			}
		}
		if (lasti < ts) {
			string s = textToTranslate.substr(lasti, ts - lasti);
			if (getChar(s, c))
				result.push_back(c);
			else
				return "Invalid MorseCode or spacing";
		}
	}

	cout << result << endl;
	return result;
}

struct ti {
	bool morseToEnglish;
	string textToTranslate;
	string eo;
	string ao;
	ti(bool f, string tt, string e): morseToEnglish(f), textToTranslate(tt), eo(e) {}
};

vector<ti> t = {
		ti(false, "THEWIZARDQUICKLYJINXEDTHEGNOMESBEFORETHEYVAPORIZED.","- .... . .-- .. --.. .- .-. -.. --.- ..- .. -.-. -.- .-.. -.-- .--- .. -. -..- . -.. - .... . --. -. --- -- . ... -... . ..-. --- .-. . - .... . -.-- ...- .- .--. --- .-. .. --.. . -.. .-.-.-"),
		ti(true, "- .... . .-- .. --.. .- .-. -.. --.- ..- .. -.-. -.- .-.. -.-- .--- .. -. -..- . -.. - .... . --. -. --- -- . ... -... . ..-. --- .-. . - .... . -.-- ...- .- .--. --- .-. .. --.. . -.. .-.-.-", "THEWIZARDQUICKLYJINXEDTHEGNOMESBEFORETHEYVAPORIZED."),

};

int main()
{
	Solution* s = new Solution();

	for (int i = 0; i < t.size(); i++) {
		t[i].ao = s->run(t[i].morseToEnglish, t[i].textToTranslate);
		assert(t[i].ao == t[i].eo);
		cout << i << " -- pass" << endl;
	}
}
