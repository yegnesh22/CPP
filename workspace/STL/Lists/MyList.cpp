#include <iostream>
#include <list>
#include <iterator>

using namespace std;


int main()
{
	list<int> numbers(0);

	for (int i = 0; i < 10; i++) {
		numbers.push_back(i);
	}
	list<int>::iterator it = numbers.begin();
	it++;
	it++;
	it++;
	*it=200;
	it = numbers.begin();
	for (; it != numbers.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}

