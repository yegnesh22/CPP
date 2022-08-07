/*
 * Base1TypeTests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#include <ExampleClasses.h>
#include <Pool.h>

void TestBase1Ptr() {
	Pooler<Base1>* Base1Pool = new Pooler<Base1> (5);
	assert(Base1Pool->capacity() == 5);
	cout << typeid(Base1Pool).name() << "Test pool create -- pass!!" << endl;

	Base1* B1Ptr[5];
	for(int i = 0; i < 5; i++) {
		B1Ptr[i] = Base1Pool->ObjAlloc();
		assert(B1Ptr[i] != nullptr);
	}
	cout << typeid(Base1Pool).name() << "Test alloc -- pass!!" << endl;

	// Data access
	for(int i = 0; i < 5; i++)
		assert(B1Ptr[i]->GetNumber() != 0);
	cout << typeid(Base1Pool).name() << "Test data access -- pass!!" << endl;

	Base1* b1p = Base1Pool->ObjAlloc();
	assert(b1p == nullptr);
	cout << typeid(Base1Pool).name() << "Test alloc request beyond pool size fail -- pass!!" << endl;

	Base1Pool->ObjDealloc(B1Ptr[0]);
	assert(B1Ptr[0] == nullptr);
	cout << typeid(Base1Pool).name() << "Test dealloc -- pass!!" << endl;

	b1p = Base1Pool->ObjAlloc();
	assert(b1p != nullptr);
	cout << typeid(Base1Pool).name() << "Test alloc after dealloc -- pass!!" << endl;
	assert(b1p->GetNumber() != 0);

	delete Base1Pool;
	b1p = Base1Pool->ObjAlloc();
	assert(b1p == nullptr);
	cout << typeid(Base1Pool).name() << "Test alloc after pool destroy should fail -- pass!!" << endl;

	return;
}
