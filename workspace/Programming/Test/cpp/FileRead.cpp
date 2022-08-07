#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ifstream f("test1.cpp");
	string line;

	while (getline(f, line)) {
		cout << line << endl;
	}
	f.close();

	return 0;
}
