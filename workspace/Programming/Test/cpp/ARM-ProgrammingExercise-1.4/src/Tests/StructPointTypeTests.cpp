/*
 * StructPointTypesTest.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#include <ExampleClasses.h>
#include <Pool.h>

void TestStructPointTypePtr() {
	cout << "Running test:" << __func__ << endl;
	Pooler<Point>* PPool = new Pooler<Point> (5);
	assert(PPool->capacity() == 5);
	cout << typeid(PPool).name() << "Test pool create -- pass!!" << endl;

	Point* PPtr[5];
	for(int i = 0; i < 5; i++) {
		PPtr[i] = PPool->ObjAlloc();
		assert(PPtr[i] != nullptr);
	}
	cout << typeid(PPool).name() << "Test alloc -- pass!!" << endl;

	for(int i = 0; i < 5; i++) {
		PPtr[i]->x = 100 + i;
		PPtr[i]->y = 200 + i;
		PPtr[i]->z = 300 + i;
		assert(PPtr[i]->x == (100 + i) && PPtr[i]->y == (200 + i) && PPtr[i]->z == (300 + i));
	}
	cout << typeid(PPool).name() << "Test data access -- pass!!" << endl;

	Point* PPtrn = PPool->ObjAlloc();
	assert(PPtrn == nullptr);
	cout << typeid(PPool).name() << "Test alloc request beyond pool size fail -- pass!!" << endl;

	PPool->ObjDealloc(PPtr[0]);
	assert(PPtr[0] == nullptr);
	cout << typeid(PPool).name() << "Test dealloc -- pass!!" << endl;
	PPtrn = PPool->ObjAlloc();
	assert(PPtrn != nullptr);
	cout << typeid(PPool).name() << "Test alloc after dealloc -- pass!!" << endl;
	PPtrn->x = 50;
	PPtrn->y = 60;
	PPtrn->z = 70;
	assert(PPtrn->x == 50 && PPtrn->y == 60 && PPtrn->z == 70);

	delete PPool;
	PPtrn = PPool->ObjAlloc();
	assert(PPtrn == nullptr);
	cout << typeid(PPool).name() << "Test alloc after pool destroy should fail -- pass!!" << endl;

	return;
}
