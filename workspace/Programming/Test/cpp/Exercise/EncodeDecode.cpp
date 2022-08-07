#include <bits/stdc++.h>

using namespace std;

string encode(string s) {
	if (s.empty())
		return s;

	string result;
	size_t i = 0;

	while (i < s.length()) {
		size_t j = i+1;
		while (j < s.length() && s[i] == s[j]) j++;
		result += ((j - i) > 1 ? to_string(j-i): "") + s[i];
		i = j;
	}

	return result;
}

string decode(string s) {
	if (s.empty())
		return s;

	size_t sl = s.length();
	string cs = "";
	string result;
	for (size_t i = 0; i < sl; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			int count = (!cs.empty()) ? stoi(cs) : 1;
			while (count--)
				result.push_back(s[i]);
			cs = "";
		} else
			cs.push_back(s[i]);
	}

	return result;
}

struct ti {
	string i;
	string e;
	string d;
	ti(string i, string e, string d): i(i), e(e), d(d) {}
};

vector<ti> tests = {
	ti("aaaabbccca", "4a2b3ca", "aaaabbccca"),
	ti("abcd", "abcd", "abcd"),
	ti("", "", ""),
};

int main()
{
	int i = 0;
	for (auto t: tests) {
		string e = encode(t.i);
		assert(e == t.e);
		string d = decode(e);
		assert(d == t.d);
		cout << i++ << " -- pass" << endl;
	}
	return 0;
}
