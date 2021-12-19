#include <iostream>
#include <map>

using namespace std;

int main()
{
	multimap<int, string> lookup;

	lookup.insert(make_pair(30, "Mike"));
	lookup.insert(make_pair(10, "Vicky"));
	lookup.insert(make_pair(30, "Raj"));
	lookup.insert(make_pair(20, "bob"));

	for(multimap<int,string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
		cout << it->first << ":" << it->second << endl;
	}

	cout << "######" << endl;
	// This call gets the first and last iteratior with the same key.
	pair<multimap<int, string>::iterator, multimap<int, string>::iterator> its = lookup.equal_range(30);

	for(multimap<int, string>::iterator it = its.first; it != its.second; it++) {
		cout << it->first << ":" << it->second << endl;
	}
	return 0;
}
