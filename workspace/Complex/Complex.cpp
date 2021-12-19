#include "Complex.h"

namespace complexns {
	// Default empty constructor
	Complex::Complex() : m_real(0), m_imag(0) {}

	// Constructor which takes real and imaginary values as parameter
	Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

	// Copy constructor
	Complex::Complex(const Complex& other) {
		m_real = other.m_real;
		m_imag = other.m_imag;
	}

	// Public method to access the private data members
	double Complex::getReal(void) const {
		return m_real;
	}

	// Public method to access the private data members
	double Complex::getImag(void) const {
		return m_imag;
	}

	// Overloading assignment operator
	const Complex& Complex::operator=(const Complex& other) {
		m_real = other.m_real;
		m_imag = other.m_imag;
		return *this;
	}

	// Overloading comparison operator '=='
	bool Complex::operator==(const Complex& other) const {
		return ((m_real == other.m_real) && (m_imag == other.m_imag));
	}

	// Overloading comparison operator '!='
	bool Complex::operator!=(const Complex& other) const {
		return !(*this == other);
	}

	// Overloading left shift operator
	ostream& operator<<(ostream& out, const Complex& c) {
		out << "(" << c.getReal() << "," << c.getImag() << ")";
		return out;
	}

	// Overloading addition operator '+'
	Complex operator+(const Complex& c1, const Complex& c2) {
		return Complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
	}

	// Overloading addition operator '+'
	Complex operator+(const Complex& c, double d) {
		return Complex(c.getReal() + d, c.getImag());
	}

	// Overloading addition operator '+'
	Complex operator+(double d, const Complex& c) {
		return Complex(c.getReal() + d, c.getImag());
	}
}