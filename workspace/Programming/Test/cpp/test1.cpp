#include <iostream>

using namespace std;

int main()
{
	string s = "abcd";
	string t;

	t.append(s, 0,-1);

	cout << s << endl;
	cout << t << endl;
}

