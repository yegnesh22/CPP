/*
 * ByteTypeTests.cpp
 *
 *  Created on: Jul 28, 2022
 *      Author: ysiyer
 */


#include <ExampleClasses.h>
#include <Pool.h>

// TCs - pool create, alloc, dealloc, access after dealloc, new alloc, pool destroy.
// Property tests - size, capacity, full, empty
void TestByteTypeVar() {
	cout << "Running test:" << __func__ << endl;
	Pooler<ByteType> BTPool; // Pooler Variable declaration with 1 object;
	bool stat;
	cout << typeid(ByteType).name() << "Test -- Pool Create -- Pass!!" << endl;
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 0);
	assert(BTPool.full() == false);
	assert(BTPool.empty() == true);
	cout << typeid(ByteType).name() << "Test -- Prop Check -- Pass!!" << endl;

	ByteType* btp1 = BTPool.ObjAlloc(); // Test step
	assert(btp1 != nullptr);
	cout << typeid(btp1).name() << "Test -- Alloc -- Pass!!" << endl;
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 1);
	assert(BTPool.full() == true);
	assert(BTPool.empty() == false);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	*btp1 = 'A'; // Test step
	ByteType btpd = *btp1; // Test step
	assert(btpd == 'A');
	*btp1 = 'B'; // Test step
	btpd = *btp1; // Test step
	assert(btpd == 'B'); // Test step
	cout << typeid(btp1).name() << "Test -- Data access -- Pass!!" << endl;

	ByteType* btp2 = BTPool.ObjAlloc(); // Test step
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 1);
	assert(BTPool.full() == true);
	assert(BTPool.empty() == false);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;
	assert(btp2 == nullptr);
	cout << typeid(btp2).name() << "Test -- Excess alloc request failure -- Pass!!" << endl;

	stat = BTPool.ObjDealloc(btp1);// Test step
	assert(btp1 == nullptr && stat == true);
	cout << typeid(btp1).name() << "Test -- Dealloc -- Pass!!" << endl;
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 0);
	assert(BTPool.full() == false);
	assert(BTPool.empty() == true);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	btp2 = BTPool.ObjAlloc();// Test step
	assert(btp2 != nullptr);
	cout << typeid(btp2).name() << "Test -- Alloc after dealloc -- Pass!!" << endl;
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 1);
	assert(BTPool.full() == true);
	assert(BTPool.empty() == false);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	btp1 = btp2; // Test step
	stat = BTPool.ObjDealloc(btp2); // Test step
	assert(btp2 == nullptr && stat == true);
	cout << typeid(btp2).name() << "Test -- Double dealloc: 1st dealloc -- Pass!!" << endl;
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 0);
	assert(BTPool.full() == false);
	assert(BTPool.empty() == true);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	stat = BTPool.ObjDealloc(btp1); // Test step
	assert(BTPool.capacity() == 1);
	assert(BTPool.size() == 0);
	assert(BTPool.full() == false);
	assert(BTPool.empty() == true);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;
	assert(btp1 == nullptr && stat == false);
	cout << typeid(btp2).name() << "Test -- Double dealloc: 2nd dealloc should fail -- Pass!!" << endl;

	return;
}

void TestByteTypePtr() {
	cout << "Running test:" << __func__ << endl;
	Pooler<ByteType>* BTPool = new Pooler<ByteType>(); // Pooler Variable declaration with 1 object;
	bool stat;
	cout << typeid(ByteType).name() << "Test -- Pool Create -- Pass!!" << endl;
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 0);
	assert(BTPool->full() == false);
	assert(BTPool->empty() == true);
	cout << typeid(ByteType).name() << "Test -- Prop Check -- Pass!!" << endl;

	ByteType* btp1 = BTPool->ObjAlloc(); // Test step
	assert(btp1 != nullptr);
	cout << typeid(btp1).name() << "Test -- Alloc -- Pass!!" << endl;
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 1);
	assert(BTPool->full() == true);
	assert(BTPool->empty() == false);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	*btp1 = 'A'; // Test step
	ByteType btpd = *btp1; // Test step
	assert(btpd == 'A');
	*btp1 = 'B'; // Test step
	btpd = *btp1; // Test step
	assert(btpd == 'B'); // Test step
	cout << typeid(btp1).name() << "Test -- Data access -- Pass!!" << endl;

	ByteType* btp2 = BTPool->ObjAlloc(); // Test step
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 1);
	assert(BTPool->full() == true);
	assert(BTPool->empty() == false);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;
	assert(btp2 == nullptr);
	cout << typeid(btp2).name() << "Test -- Excess alloc request failure -- Pass!!" << endl;

	stat = BTPool->ObjDealloc(btp1);// Test step
	assert(btp1 == nullptr && stat == true);
	cout << typeid(btp1).name() << "Test -- Dealloc -- Pass!!" << endl;
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 0);
	assert(BTPool->full() == false);
	assert(BTPool->empty() == true);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	btp2 = BTPool->ObjAlloc();// Test step
	assert(btp2 != nullptr);
	cout << typeid(btp2).name() << "Test -- Alloc after dealloc -- Pass!!" << endl;
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 1);
	assert(BTPool->full() == true);
	assert(BTPool->empty() == false);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	btp1 = btp2; // Test step
	stat = BTPool->ObjDealloc(btp2); // Test step
	assert(btp2 == nullptr && stat == true);
	cout << typeid(btp2).name() << "Test -- Double dealloc: 1st dealloc -- Pass!!" << endl;
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 0);
	assert(BTPool->full() == false);
	assert(BTPool->empty() == true);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;

	stat = BTPool->ObjDealloc(btp1); // Test step
	assert(BTPool->capacity() == 1);
	assert(BTPool->size() == 0);
	assert(BTPool->full() == false);
	assert(BTPool->empty() == true);
	cout << typeid(btp1).name() << "Test -- Prop Check -- Pass!!" << endl;
	assert(btp1 == nullptr && stat == false);
	cout << typeid(btp2).name() << "Test -- Double dealloc: 2nd dealloc should fail -- Pass!!" << endl;

	delete BTPool; // Test Step
	ByteType* p = BTPool->ObjAlloc();
	assert(p == nullptr);
	cout << typeid(BTPool).name() << "Test -- alloc after pool destroy should fail -- Pass!!" << endl;
	return;
}

void TestByteTypeMulti() {
	cout << "Running test:" << __func__ << endl;
	Pooler<ByteType>* BTPool = new Pooler<ByteType>(5);
	ByteType* btp[5];
	for (int i = 0; i < 5; i++) {
		btp[i] = BTPool->ObjAlloc();
		assert(btp[i] != nullptr);
	}
	cout << typeid(btp).name() << "Test -- alloc multiple objects one-by-one fashion -- Pass!!" << endl;
	// Access objects
	*btp[0] = 'a';
	*btp[1] = 'e';
	*btp[2] = 'i';
	*btp[3] = 'o';
	*btp[4] = 'u';
	ByteType* nbtp = btp[0];
	assert(nbtp[0] == 'a' && nbtp[1] == 'e' && nbtp[2] == 'i' && nbtp[3] == 'o' && nbtp[4] == 'u');
	cout << typeid(nbtp).name() << "Test -- array subscripted access -- Pass!!" << endl;
	assert(*(nbtp+0) == 'a' && *(nbtp+1) == 'e' && *(nbtp+2) == 'i' && *(nbtp+3) == 'o' && *(nbtp+4) == 'u');
	cout << typeid(nbtp).name() << "Test -- access using ptr arithmetic -- Pass!!" << endl;
	nbtp = BTPool->ObjAlloc();
	assert(nbtp == nullptr);
	cout << typeid(nbtp).name() << "Test -- alloc request for space more that the pool size should fail -- Pass!!" << endl;
	BTPool->ObjDealloc(btp[4]);
	assert(btp[4] == nullptr);
	cout << typeid(nbtp).name() << "Test -- dealloc one object -- Pass!!" << endl;
	nbtp = BTPool->ObjAlloc();
	assert(nbtp != nullptr);
	cout << typeid(nbtp).name() << "Test -- alloc after dealloc -- Pass!!" << endl;
	delete BTPool;
	ByteType* p = BTPool->ObjAlloc();
	assert(p == nullptr);
	cout << typeid(BTPool).name() << "Test -- alloc after pool destroy should fail -- Pass!!" << endl;
	
	return;
}
