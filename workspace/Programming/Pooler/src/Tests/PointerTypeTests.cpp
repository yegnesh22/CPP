/*
 * PointerTypeTests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */

#include <ExampleClasses.h>
#include <Pool.h>

void TestPointerTypeVar()
{
	Pooler<PointerType> PTPool(5);
	assert(PTPool.capacity() == 5);
	cout << typeid(PTPool).name() << "Test pool create -- pass!!" << endl;
	PointerType* ptp[5];

	for (int i = 0; i < 5; i++) {
		ptp[i] = PTPool.ObjAlloc();
		assert(ptp[i] != nullptr);
	}
	cout << typeid(ptp).name() << "Test alloc -- pass!!" << endl;

	// Data access
	*ptp[0] = (void*) new char;
	char* ptc = (char*) *ptp[0];
	*ptc = 'a';
	assert(*(char*)(*ptp[0]) == 'a');
	cout << typeid(ptp).name() << "Test data access(char) -- pass!!" << endl;

	*ptp[1] = (void*) new int;
	int* pti = (int *) *ptp[1];
	*pti = 0xA5A5;
	assert(*(int*)(*ptp[1]) == 0xA5A5);
	cout << typeid(ptp).name() << "Test data access(int) -- pass!!" << endl;

	PointerType* tp = PTPool.ObjAlloc();
	assert(tp == nullptr);
	cout << typeid(PTPool).name() << "Test alloc request beyond the pool size fail -- pass!!" << endl;

	delete (int*)*ptp[1];
	PTPool.ObjDealloc(ptp[1]);
	assert(ptp[1] == nullptr);
	cout << typeid(PTPool).name() << "Test dealloc  -- pass!!" << endl;

	tp = PTPool.ObjAlloc();
	assert(tp != nullptr);
	cout << typeid(PTPool).name() << "Test alloc request after dealloc -- pass!!" << endl;

	delete &PTPool;
	PointerType* p = PTPool.ObjAlloc();
	assert(p == nullptr);
	cout << typeid(PTPool).name() << "Test -- alloc after pool destroy should fail -- Pass!!" << endl;

	return;
}


