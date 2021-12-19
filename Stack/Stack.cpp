#include <iostream>
#include <stack>

using namespace std;

class NameList {
	int id;
	string name;

	public:
		NameList() : id(0), name("") {
		}

		NameList(int id, string name): id(id), name(name) {
		}

		void print() {
			cout << id << ":" << name << endl;
		}
};

int main()
{
	stack<NameList> List1c;

	List1c.push(NameList(1,"Vaishnavi"));
	List1c.push(NameList(2,"Gunja"));
	List1c.push(NameList(3,"Bhuvan"));
	List1c.push(NameList(4,"Samanvita"));
	List1c.push(NameList(5,"Maheshwar"));

	NameList &name1 = List1c.top();
	name1.print();
	List1c.pop();

	NameList &name2 = List1c.top();
	name2.print();
	List1c.pop();
}
