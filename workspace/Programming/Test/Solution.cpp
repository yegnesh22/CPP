/*
 * Solution.cpp
 *
 *  Created on: Jul 2, 2022
 *      Author: ysiyer
 */

#include <iostream>

using namespace std;
class GlobalMap
{
	static GlobalMap* instance;
	...
public:
	static GlobalMap* getInstance() {
		if (!instance) {
			instance = new GlobalMap();
			...
		}
		return instance;
	}
	....
};

int main()
{
	GlobalMap* m;
	m = new GlobalMap();
	GlobalMap* n;
	n =  new GlobalMap();
	cout << n << endl;
	cout << m << endl;

	n->setData(10);
	cout << n->getData() << endl;
	cout << m->getData() << endl;

	return 0;
}


