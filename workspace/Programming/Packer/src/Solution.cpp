/*
 * Solution.cpp
 *
 *  Created on: Aug 5, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>

using namespace std;

class packed {
private:
	unsigned char a[32] {0};
	struct maskShift {
		unsigned char mask;
		unsigned char shift;
	};

	const maskShift ms[2] = {
			{.mask = 0x0F, .shift = 0}, // lower nibble
			{.mask = 0xF0, .shift = 4}, // upper nibble
	};

public:
	// limit the index value to 63. (index & 0x3F).
	// index is halved since one byte holds 2 values.
	// if index is even, i.e 0,2,4,...,62, value is stored in the lower nibble
	// if index is odd, i.e 1,3,5,...,63, value is stored in the upper nibble

	void store(int index, unsigned char value) {
		int offset = (index & 0x3F) >> 1;
		int msi = index & 0x1;
		int mask = ms[msi].mask;
		int shift = ms[msi].shift;

		// Mask the other nibble and update the relevant nibble.
		a[offset] = (a[offset] & ~mask) | ((value & 0xF) << shift);
	}

	unsigned char recall(int index) {
		int offset = (index & 0x3F) >> 1;
		int msi = index & 0x1;

		return ((a[offset] & ms[msi].mask) >> ms[msi].shift);
	}
};

int main() {
	packed ps;

	ps.store(1, 0x5);
	ps.store(2, 0xA);
	ps.store(3, 0xF);
	ps.store(62, 0x2);

	assert(0x0 == ps.recall(0)); // uninitalized lower nibble
	assert(0x5 == ps.recall(1)); // initialized upper nibble
	cout << "Test 1: uninitalized lower nibble, initialized upper nibble -- pass" << endl;

	assert(0xA == ps.recall(2)); // initialized lower nibble
	assert(0xF == ps.recall(3)); // initialized lower nibble
	cout << "Test 2: initalized lower nibble, initialized upper nibble -- pass" << endl;

	assert(0x2 == ps.recall(62)); // initialized lower nibble
	assert(0x0 == ps.recall(63)); // uninitialize upper nibble
	cout << "Test 3: initalized lower nibble, uninitialized upper nibble -- pass" << endl;

	assert(0x0 == ps.recall(48)); // uninitialized lower nibble
	assert(0x0 == ps.recall(49)); // uninitialized upper nibble
	cout << "Test 4: uninitalized lower nibble, uninitialized upper nibble -- pass" << endl;

	return 0;
}



