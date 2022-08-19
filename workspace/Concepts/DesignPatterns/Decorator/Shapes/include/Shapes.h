/*
 * Shapes.h
 *
 *  Created on: Aug 15, 2022
 *      Author: ysiyer
 */

#ifndef SHAPES_H_
#define SHAPES_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

class Shapes {
public:
	string name;
	virtual double perimeter() = 0;
	virtual double area() = 0;
	virtual void describe() {
		cout << "Shape:" << name << endl;
		cout << "Area:" << area() << endl;
		cout << "Perimeter:" << perimeter() << endl;
	}
};

class Rectangle: public Shapes {
private:
	double m_l;
	double m_b;
public:
	Rectangle(double l = 0, double b = 0): m_l(l), m_b(b) {
		name = "Rectangle";
	}
	virtual double perimeter() {
		return 2 * (m_l + m_b);
	}
	virtual double area() {
		return m_l * m_b;
	}
};

class Square: public Shapes {
private:
	double m_s;
public:
	Square(double s = 0): m_s(s) {
		name = "Square";
	}
	virtual double perimeter() {
		return 4 * m_s;
	}
	virtual double area() {
		return m_s * m_s;
	}
};

class Circle: public Shapes {
private:
	double m_r;
public:
	Circle(double r = 0): m_r(r) {
		name = "Circle";
	}
	virtual double perimeter() {
		return 2 * M_PI * m_r;
	}
	virtual double area() {
		return M_PI * m_r * m_r;
	}
};

class Triangle: public Shapes {
private:
	double m_s1;
	double m_s2;
	double m_s3;
public:
	Triangle(double s1 = 0, double s2 = 0, double s3 = 0): m_s1(s1), m_s2(s2), m_s3(s3) {
		name = "Triangle";
	}
	virtual double perimeter() {
		return m_s1 + m_s2 + m_s3;
	}
	virtual double area() {
		double s = perimeter() / 2;
		return sqrt(s * (s - m_s1) * (s - m_s2) * (s - m_s3));
	}
};

class ColoredShape: public Shapes {
private:
	Shapes& m_shape;
	string m_color;
public:
	ColoredShape(Shapes& s, string c): m_shape(s), m_color(c) {}
	virtual double area() {
		return m_shape.area();
	}
	virtual double perimeter() {
		return m_shape.perimeter();
	}
	virtual void describe() {
		cout << "Color:" << m_color << endl;
		m_shape.describe();
	}
};

class FinishedShape: public Shapes {
private:
	Shapes& m_shape;
	string m_finish;
public:
	FinishedShape(Shapes& s, string f): m_shape(s), m_finish(f) {}
	virtual double area() {
		return m_shape.area();
	}
	virtual double perimeter() {
		return m_shape.perimeter();
	}
	virtual void describe() {
		cout << "Surface:" << m_finish << endl;
		m_shape.describe();
	}
};

double calcTotalArea(vector<Shapes*> objs) {
	double t = 0;
	for (auto& o: objs)
		t += o->area();

	return t;
}

#endif /* SHAPES_H_ */

