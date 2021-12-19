#pragma once

#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>

using namespace std;

namespace complexns {
	class Complex {
	private:
		double m_real;
		double m_imag;

	public:
		Complex();
		Complex(double, double);
		Complex(const Complex&);
		double getReal (void) const;
		double getImag (void) const;
		const Complex& operator=(const Complex&);
		bool operator==(const Complex&) const;
		bool operator!=(const Complex&) const;
	};

	ostream& operator<<(ostream&, const Complex&);
	Complex operator+(const Complex&, const Complex&);
	Complex operator+(const Complex&, double );
	Complex operator+(double, const Complex&);
}
#endif