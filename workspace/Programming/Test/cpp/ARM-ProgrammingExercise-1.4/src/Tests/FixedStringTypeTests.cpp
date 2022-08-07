/*
 * FixedStringTypeTests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#include <ExampleClasses.h>
#include <cstring>
#include <Pool.h>

void TestFixedStringTypePtr() {
	cout << "Running test:" << __func__ << endl;
	Pooler<FixedStringType>* FSTPool = new Pooler<FixedStringType> (5);
	assert(FSTPool->capacity() == 5);
	cout << typeid(FSTPool).name() << "Test pool create -- pass!!" << endl;

	FixedStringType* fstp[5];
	for (int i = 0; i < 5; i++) {
		fstp[i] = FSTPool->ObjAlloc();
		assert(fstp[i] != nullptr);
		sprintf((char*)&fstp[i][0], "string %d", i);
	}
	cout << typeid(FSTPool).name() << "Test alloc -- pass!!" << endl;
	for (int i = 0; i < 5; i++) {
		string s = "string " + to_string(i);
		assert(strcmp((char*)&fstp[i][0],s.c_str()) == 0);
	}
	cout << typeid(FSTPool).name() << "Test data access -- pass!!" << endl;

	FixedStringType* fp = FSTPool->ObjAlloc();
	assert(fp == nullptr);
	cout << typeid(FSTPool).name() << "Test alloc request beyond pool size fail -- pass!!" << endl;

	FSTPool->ObjDealloc(fstp[0]);
	assert(fstp[0] == nullptr);
	cout << typeid(FSTPool).name() << "Test dealloc -- pass!!" << endl;
	fp = FSTPool->ObjAlloc();
	assert(fp != nullptr);
	cout << typeid(FSTPool).name() << "Test alloc after dealloc -- pass!!" << endl;
	sprintf((char*)&fp[0], "str 0");
	assert(strcmp((char*)&fp[0], "str 0") == 0);

	delete FSTPool;
	fp = FSTPool->ObjAlloc();
	assert(fp == nullptr);
	cout << typeid(FSTPool).name() << "Test alloc after pool destroy should fail -- pass!!" << endl;
	return;
}

