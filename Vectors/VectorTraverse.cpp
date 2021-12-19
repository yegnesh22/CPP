#include <iostream>
#include <vector>

using namespace std;

void create_list(vector<int> &my_list)
{
	for (int i = 1; i <= 100; i++) {
		my_list.push_back(i);
	}
}

int main()
{
	vector<int> my_list;
	int reverse_index;

	create_list(my_list);
	cout << "Enter the reverse index: " << flush;
	cin >> reverse_index;

	if (reverse_index >= my_list.size()) {
		cout << "List too short!!" << endl;
		exit(0);
	}

	vector<int>::iterator it = my_list.begin();
	vector<int>::iterator rit = my_list.begin();
	for (;	it != my_list.end(); it++) {
		if (reverse_index >= 0) {
			reverse_index --;
		} else {
			rit ++;
		}
	}

	cout << "Element :" << *rit << endl;
	
	return 0;
}

