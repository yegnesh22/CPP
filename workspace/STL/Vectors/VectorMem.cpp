#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> numbers(0);
	int capacity = numbers.capacity();

	cout << "size:" << numbers.size() << endl;
	cout << "capacity:" << capacity << endl;

	for (int i = 0; i < 1000; i ++) {
		if (numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			cout << "capacity:" << capacity << endl;
		}
		numbers.push_back(i);
	}
}
