/*
 * Solution.cpp
 *
 *  Created on: Mar 30, 2022
 *      Author: ysiyer
 */

#include <iostream>
#include <cassert>

using namespace std;

/*
 * Implement the Bitset class:
 *
 * Bitset(int size) Initializes the Bitset with size bits, all of which are 0.
 *
 * void fix(int idx) Updates the value of the bit at the index idx to 1.
 * - If the value was already 1, no change occurs.
 *
 * void unfix(int idx) Updates the value of the bit at the index idx to 0.
 * - If the value was already 0, no change occurs.
 *
 * void flip() Flips the values of each bit in the Bitset.
 *  - In other words, all bits with value 0 will now have value 1 and vice versa.
 *
 * boolean all() Checks if the value of each bit in the Bitset is 1.
 *  - Returns true if it satisfies the condition, false otherwise.
 *
 * boolean one() Checks if there is at least one bit in the Bitset with value 1.
 *  - Returns true if it satisfies the condition, false otherwise.
 *
 * int count() Returns the total number of bits in the Bitset which have value 1.
 *
 * String toString() Returns the current composition of the Bitset.
 * 	- Note that in the resultant string, the character at the ith index should
 * 	- coincide with the value at the ith bit of the Bitset.
 */

class Bitset {
private:
	string m_inv_str;
	string m_str;
	size_t m_nb;
	size_t m_sbc;
public:
	Bitset(int size) {
		m_nb = (size_t)size;
		m_str.resize(m_nb, '0');
		m_inv_str.resize(m_nb, '1');
		m_sbc = 0;
	}

	void fix(int idx) {
		if (m_str[idx] == '0') {
			m_str[idx] = '1';
			m_inv_str[idx] = '0';
			m_sbc++;
		}
	}

	void unfix(int idx) {
		if (m_str[idx] == '1') {
			m_str[idx] = '0';
			m_inv_str[idx] = '1';
			m_sbc--;
		}
	}

	void flip() {
		string t = m_inv_str;
		m_inv_str = m_str;
		m_str = t;
		m_sbc = m_nb - m_sbc;
	}

	int count() {
		return m_sbc;
	}

	bool all() {
		return m_sbc == m_nb;
	}

	bool one() {
		return m_sbc >= 1;
	}

	string toString() {
		return m_str;
	}
};

int main()
{
	Bitset bs(5);

	bs.fix(3);
	assert(bs.toString() == "00010");
	bs.fix(1);
	assert(bs.toString() == "01010");
	bs.flip();
	assert(bs.toString() == "10101");
	assert(bs.all() == false);
	bs.unfix(0);
	assert(bs.toString() == "00101");
	bs.flip();
	assert(bs.toString() == "11010");
	assert(bs.one() == true);
	bs.unfix(0);
	assert(bs.toString() == "01010");
	assert(bs.count() == 2);
	assert(bs.toString() == "01010");
	cout << "passed!!" << endl;
}
