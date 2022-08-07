/*
 * DerivedTypeTests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#include <ExampleClasses.h>
#include <Pool.h>

void TestDerivedPtr() {
	Pooler<Derived>* DerivedPool = new Pooler<Derived> (5);
	assert(DerivedPool->capacity() == 5);
	cout << typeid(DerivedPool).name() << "Test pool create -- pass!!" << endl;

	Derived* D1Ptr[5];
	for(int i = 0; i < 5; i++) {
		D1Ptr[i] = DerivedPool->ObjAlloc();
		assert(D1Ptr[i] != nullptr);
	}
	cout << typeid(DerivedPool).name() << "Test alloc -- pass!!" << endl;

	// Data access
	for(int i = 0; i < 5; i++)
		assert(D1Ptr[i]->GetNumber1() != 0 && D1Ptr[i]->GetNumber2() != 0 && D1Ptr[i]->GetNumber3() != 0);
	cout << typeid(DerivedPool).name() << "Test data access -- pass!!" << endl;

	Derived* D1p = DerivedPool->ObjAlloc();
	assert(D1p == nullptr);
	cout << typeid(DerivedPool).name() << "Test alloc request beyond pool size fail -- pass!!" << endl;

	DerivedPool->ObjDealloc(D1Ptr[0]);
	assert(D1Ptr[0] == nullptr);
	cout << typeid(DerivedPool).name() << "Test dealloc -- pass!!" << endl;

	D1p = DerivedPool->ObjAlloc();
	assert(D1p != nullptr);
	cout << typeid(DerivedPool).name() << "Test alloc after dealloc -- pass!!" << endl;
	assert(D1p->GetNumber1() != 0 && D1p->GetNumber2() != 0 && D1p->GetNumber3() != 0);

	delete DerivedPool;
	D1p = DerivedPool->ObjAlloc();
	assert(D1p == nullptr);
	cout << typeid(DerivedPool).name() << "Test alloc after pool destroy should fail -- pass!!" << endl;

	return;
}
