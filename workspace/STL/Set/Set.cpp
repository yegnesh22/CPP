#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> numbers;

	numbers.insert(50);
	numbers.insert(20);
	numbers.insert(10);
	numbers.insert(30);
	numbers.insert(30);
	numbers.insert(40);

	for (set<int>::iterator it = numbers.begin();
			it != numbers.end();
			it++) {
		cout << *it << endl;
	}

	set<int>::iterator itFind = numbers.find(130);
	if (itFind != numbers.end()) {
		cout << "Found :" << *itFind << endl;
	} else {
		cout << "Not Found" << endl;
	}
	if (numbers.count(130)) {
		cout << "Found" << endl;
	} else {
		cout << "Not Found" << endl;
	}
	return 0;
}

