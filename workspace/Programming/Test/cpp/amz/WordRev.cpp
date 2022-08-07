#include <bits/stdc++.h>

using namespace std;

void ReverseString(string& i, size_t s, size_t e) {
	char t;

	while (s < e) {
		t = i[e];
		i[e] = i[s];
		i[s] = t;
		s++;
		e--;
	}

	return;
}

string ReverseWords(string s) {
	size_t sl = s.length();
	string s2 = s;
	char t;

	// reverse the string
	ReverseString(s2, 0, sl-1);
	
	// reverse the words
	size_t lpos = 0;
	for (size_t i = 0; i < sl; i++) {
		if (s2[i] == ' ') {
			ReverseString(s2, lpos, i-1);
			lpos = i+1;
			while(s2[lpos] == ' ') lpos++;
		}
	}
	if (lpos < sl)
		ReverseString(s2, lpos, sl-1);
	return s2;
}

int main()
{
	string s1 = "Hello World";
	cout << s1 << ":" << ReverseWords(s1) << endl;
	return 0;
}
