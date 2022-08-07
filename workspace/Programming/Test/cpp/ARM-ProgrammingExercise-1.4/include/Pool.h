/*
 * Pool.h
 *
 *  Created on: Jul 27, 2022
 *      Author: ysiyer
 */

/*
 * Known limitation: This implementation works well for objects/data types with default
 * constructors with 0 parameters. For objects without constructors with 0 parameters,
 * this will fail to compile.
 */

#ifndef INCLUDE_POOL_H_
#define INCLUDE_POOL_H_

#include <bits/stdc++.h>

using namespace std;

const int g_MaxNumberOfObjectsInPool = 1000;

template<typename T> class Pooler {
private:
	void* m_PoolStart {nullptr};
	unsigned short m_psize;
	vector<bool> m_lkp;
	list<T*> m_avail;
public:
	// functions mentioned in the task
	Pooler();
	Pooler(unsigned short);
	~Pooler();
	T* ObjAlloc();
	bool ObjDealloc(T*&);

	// Helper functions.
	int size();
	int capacity();
	bool full();
	bool empty();
};

// "Create a pool" - with 1 object
template<typename T> Pooler<T>::Pooler() {
	cout << "Creating a pool with 1 object" << endl;
	m_PoolStart = new char[sizeof(T)];
	m_psize = 1;
	m_avail.push_back((T*)m_PoolStart);
	m_lkp.resize(1);
	m_lkp[0] = false;
}

// "Create a pool" - with n objects
template<typename T> Pooler<T>::Pooler(unsigned short n) {
	if (n <= g_MaxNumberOfObjectsInPool) {
		cout << "Creating a pool with " << n << (n > 1 ? " objects" : " object") << endl;
		m_PoolStart = new char [n * sizeof(T)];
		m_psize = n;
		m_lkp.resize(n);
		for (unsigned short i = 0; i < n; i++) {
			m_avail.push_back(((T*)m_PoolStart)+i);
			m_lkp[i] = false;
		}
	}
}

template<typename T> Pooler<T>::~Pooler() {
	m_psize = 0;
	m_avail.clear();
	m_lkp.resize(0);
	delete[] (char*)m_PoolStart;
	cout << "Pool Destructed" << endl;
}

// "Allocate an object from this pool"
template<typename T> T* Pooler<T>::ObjAlloc() {
	if (m_avail.empty()) {
		cout << "Cannot allocate anymore on this pool with size "
				<< m_psize << endl;
		return nullptr;
	}
	T L;
	T* addr = m_avail.front();
	memcpy(addr, &L, sizeof(L));
	m_avail.pop_front();
	m_lkp[addr - (T*)m_PoolStart] = true;
	return addr;
}

// "Deallocate an object from this pool"
template<typename T> bool Pooler<T>::ObjDealloc(T*& addr) {
	size_t index = addr - (T*)m_PoolStart;
	bool stat = false;

	if ((addr == nullptr) || (index >= m_psize)) {
		cout << (void*) addr << " not in this pool" << endl;
		return stat;
	}

	if (m_lkp[index] == true) {
		m_avail.push_back(addr);
		m_lkp[index] = false; // to avoid duplication
		stat = true;
	}

	addr = nullptr; // To prevent access after Dealloc
	return stat;
}

// Helper - returns number of used slots in the pool
template<typename T> int Pooler<T>::size() {
	return m_psize - m_avail.size();
}

// Helper - returns total number of slots in the pool
template<typename T> int Pooler<T>::capacity() {
	return m_psize;
}

// Helper - returns true if the pool is full
template<typename T> bool Pooler<T>::full() {
	return m_avail.size() == 0;
}

// Helper - returns true if the pool is empty
template<typename T> bool Pooler<T>::empty() {
	return m_avail.size() == m_psize;
}

#endif /* INCLUDE_POOL_H_ */
