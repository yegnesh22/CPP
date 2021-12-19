#ifndef __TEST_H__
#define __TEST_H__

#include <iostream>
using namespace std;

class Test {
	protected:
		int id;
		string name;
	public:
		Test(): id(0), name("") {
		}

		Test(int id, string name): id(id), name(name) {
		}

		Test& operator= (Test &other) {
			id = other.id;
			name = other.name;
			return *this;
		}

		friend ostream& operator<< (ostream& out, const Test& other) {
			out << other.id << ":" << other.name ;
			return out;
		}
};

#endif
