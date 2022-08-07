/*
 * Ring.h
 *
 *  Created on: Jul 10, 2022
 *      Author: ysiyer
 */

#ifndef RING_H_
#define RING_H_

#include <iostream>

using namespace std;

template<typename T>
class ring {
private:
	T* m_values;
	int m_size;
	int m_pos;
public:
	// For C++98 and C++11 style iterator mode access
	class iterator;
	ring(int n): m_values(nullptr), m_size(n), m_pos(0) {
		m_values = new T[n];
	}

	~ring() {
		delete[] m_values;
	}

	void add(T s) {
		m_values[m_pos++] = s;
		if (m_pos == m_size)
			m_pos = 0;
	}

	T& get(int pos) {
		return m_values[pos];
	}

	// For C++98 and C++11 style iterator mode access
	iterator begin() {
		return iterator(0, *this);
	}

	// For C++98 and C++11 style iterator mode access
	iterator end() {
		return iterator(m_size, *this);
	}

	int size() {
		return m_size;
	}

	// For array style access
	T& operator[](int n) {
		return m_values[n];
	}
};

// For C++98 and C++11 style iterator mode access
template<typename T>
class ring<T>::iterator {
private:
	int m_pos;
	ring& m_ring;
public:
	iterator(int pos, ring& r): m_pos(pos), m_ring(r) {}

	iterator operator++(int) {
		cout << "pre-increment" << endl;
		iterator old = *this;
		++(*this);
		return old;
	}

	iterator operator++() {
		cout << "post increment" << endl;
		m_pos++;
		return *this;
	}

	// For checking it != <var>.end();
	bool operator !=(const iterator& o) const{
		return m_pos != o.m_pos;
	}

	// For accessing the element using the *it method
	T& operator*() {
		return m_ring.get(m_pos);
	}
};

#endif /* RING_H_ */
