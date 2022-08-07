/*
 * Solution.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: ysiyer
 */

#include <iostream>

using namespace std;

template <class A, class B>
auto Add(A a, B b) -> decltype(a+b) {
	return a + b;
}

int main()
{
	auto a = 10;
	auto b = 20.5;

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(Add(a, b)).name() << endl;

	return 0;
}


