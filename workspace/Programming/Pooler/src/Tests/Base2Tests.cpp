/*
 * Base2TypeTests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#include <ExampleClasses.h>
#include <Pool.h>

void TestBase2Ptr() {
	Pooler<Base2>* Base2Pool = new Pooler<Base2> (5);
	assert(Base2Pool->capacity() == 5);
	cout << typeid(Base2Pool).name() << "Test pool create -- pass!!" << endl;

	Base2* B2Ptr[5];
	for(int i = 0; i < 5; i++) {
		B2Ptr[i] = Base2Pool->ObjAlloc();
		assert(B2Ptr[i] != nullptr);
	}
	cout << typeid(Base2Pool).name() << "Test alloc -- pass!!" << endl;

	// Data access
	for(int i = 0; i < 5; i++)
		assert(B2Ptr[i]->GetNumber() != 0);
	cout << typeid(Base2Pool).name() << "Test data access -- pass!!" << endl;

	Base2* B2p = Base2Pool->ObjAlloc();
	assert(B2p == nullptr);
	cout << typeid(Base2Pool).name() << "Test alloc request beyond pool size fail -- pass!!" << endl;

	Base2Pool->ObjDealloc(B2Ptr[0]);
	assert(B2Ptr[0] == nullptr);
	cout << typeid(Base2Pool).name() << "Test dealloc -- pass!!" << endl;

	B2p = Base2Pool->ObjAlloc();
	assert(B2p != nullptr);
	cout << typeid(Base2Pool).name() << "Test alloc after dealloc -- pass!!" << endl;
	assert(B2p->GetNumber() != 0);

	delete Base2Pool;
	B2p = Base2Pool->ObjAlloc();
	assert(B2p == nullptr);
	cout << typeid(Base2Pool).name() << "Test alloc after pool destroy should fail -- pass!!" << endl;

	return;
}
