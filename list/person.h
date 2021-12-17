#ifndef __PERSON_H__
#define __PERSON_H__

#include <iostream>
#include <map>

using namespace std;

class Person {
	private:
		int m_age;
		string m_name;
	public:
		Person();
		Person(string, int);
		Person(const Person &);
		void print() const;
		bool operator<(const Person &) const;
};

#endif
