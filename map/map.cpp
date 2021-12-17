#include "person.h"

int main() 
{
	map<Person, int> people;

	people[Person("Mike",30)] = 1;
	people[Person("Mike",40)] = 2;
	people[Person("Thomas",20)] = 3;
	people[Person("Raj",10)] = 4;
	people[Person("Mike",30)] = 5;


	for (map<Person, int>::iterator it = people.begin();
			it != people.end(); it++) {
		cout << it->second << ":";
		it->first.print();
		cout << endl;
	}
	return 0;
}
