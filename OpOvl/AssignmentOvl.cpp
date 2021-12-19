#include <iostream>

using namespace std;

class student {
	int id;
	string name;

	public:
	student() : id(0), name("") {
	}

	student(int id, string name): id(id), name(name) {
	}

	void print() {
		cout << id << ":" << name << endl;
	}

	const student &operator=(const student &other) {
		cout << __func__ << endl;
		name = other.name;
		id = other.id;

		return *this;
	}
};

int main()
{
	student s1(10, "Mike");
	cout << "Print s1" << flush;
	s1.print();

	student s2(15, "Bob");
	cout << "Print s1" << flush;
	s1.print();

	student s3;
	s3 = s2;
	s3.print();

	student s4;
	s4.operator=s2;
	s4.print();

	return 0;
}
