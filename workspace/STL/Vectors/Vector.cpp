#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> strings(1);
	int capacity = strings.capacity();
	cout << capacity << endl;
	strings.push_back("one");
	cout << strings.capacity() << endl;
	strings.push_back("two");
	cout << strings.capacity() << endl;
	strings.push_back("three");
	cout << strings.capacity() << endl;
	strings.push_back("four");
	cout << strings.capacity() << endl;
	strings[0]="zero";
	cout << strings.capacity() << endl;

	for (vector<string>::iterator it = strings.begin();
			it != strings.end();
			it++)
		cout << &(*it) << ":" << *it << endl;

	strings.clear();
	cout << strings.capacity() << endl;
	return 0;
}
