#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<string, int> ages;
	string name = "Yegnesh";
	int age = 38;

	ages["Mike"] = 40;
	ages["Raj"] = 20;
	ages["Vicky"] = 30;

	cout << ages["Raj"] << endl;
	ages["Mike"] = 70;

	ages.insert(pair<string, int>("Peter",100));
	ages.insert(make_pair("Rishi",50));
	ages.insert(make_pair(name, age));

	if (ages.find("Vicky") != ages.end())
		cout << "Found Vicky" << endl;
	else
		cout << "Vicky not found" << endl;

	for(map<string, int>::iterator it = ages.begin();
			it != ages.end();
			it++) {
		pair<string, int> age = *it;
		cout << age.first << ": " << age.second << endl;
	}
	return 0;
}
