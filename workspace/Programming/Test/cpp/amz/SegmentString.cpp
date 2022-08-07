#include <bits/stdc++.h>

using namespace std;

bool CheckSegment(string& s, set<string>& dict) {
	size_t ss = s.length();

	for(size_t i = 0; i < ss; i++) {
		string sl = s.substr(0, i+1);
		string sr = s.substr(i+1, ss-1);

		cout << "l:" << sl << " r:" << sr << endl;
		if (dict.find(sl) != dict.end() && dict.find(sr) != dict.end())
			return true;
	}

	return false;
}

int main()
{
	set<string> dict = {"apple", "pie", "pear"};
	string s1 = "applepie";
	string s2 = "applepeer";
	string s3 = "applepear";

	cout << s1 << ":" << CheckSegment(s1, dict) << endl;
	cout << s2 << ":" << CheckSegment(s2, dict) << endl;
	cout << s3 << ":" << CheckSegment(s3, dict) << endl;

	return 0;
}
