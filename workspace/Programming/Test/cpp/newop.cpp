#include <bits/stdc++.h>

using namespace std;

int main() {
	char* c;
	char* d;

	c = new char;
	d = c;
	delete c;

	*c = 'A';
	cout << "c:" << *c << " d:" << *d << endl;
	*d = 'B';
	cout << "c:" << *c << " d:" << *d << endl;
	*d = 'E';
	cout << "c:" << *c << " d:" << *d << endl;

	return 0;
}
