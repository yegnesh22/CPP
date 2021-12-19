#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NameList {
	int id;
	string name;

public:
	NameList() : id(0), name("") {
	}

	NameList(int id, string name) : id(id), name(name) {
	}

	void print() {
		cout << id << ":" << name << endl;
	}

	// Use the below method to sort the list by overloading the 
	// '<' operator.
	/* bool operator <(NameList &other) {
		return (name < other.name);
	} */

	// Use the below method to define a custom comparsion method for
	// sorting the objects.
	friend bool comp (NameList &, NameList &);
};

// Use the below method to define a custom comparsion method for
// sorting the objects.
bool comp(NameList &o1, NameList &o2)
{
	return (o1.id < o2.id);
}

int main()
{
	vector<NameList> list_1c;

	list_1c.push_back(NameList(2,"Bhuvan"));
	list_1c.push_back(NameList(5,"Gunja"));
	list_1c.push_back(NameList(1,"Vaishnavi"));
	list_1c.push_back(NameList(4,"Samanvita"));
	list_1c.push_back(NameList(3,"Samhita"));

	// Use the below method to sort the list by overloading the
	// '<' operator
	// sort(list_1c.begin(), list_1c.end());

	// Use the below method to define a custom comparsion method for
	// sorting the objects.
	sort(list_1c.begin(), list_1c.end(), comp);

	for (vector<NameList>::iterator it = list_1c.begin();
			it != list_1c.end();
			it++) {
		it->print();
	}
}
