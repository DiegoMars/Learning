#include "Triangle.h"
#include <cmath>

// Construct a default circle object
Triangle::Triangle()
{
	side1 = 1.0;
	side2 = 1.0;
	side3 = 1.0;
}

// Construct a circle object with specified radius
Triangle::Triangle(double s1, double s2, double s3) 
	: side1(s1), side2(s2), side3(s3)
{}
Triangle::Triangle(double s1, double s2, double s3, const string& color, bool filled)
	: side1(s1), side2(s2), side3(s3)
{
	side1 = s1;
	setColor(color);
	setFilled(filled);
}

// Getters
double Triangle::getSide1() const {
	return side1;
}
double Triangle::getSide2() const {
	return side2;
}
double Triangle::getSide3() const {
	return side3;
}

// Return the area of this circle
double Triangle::getArea() const
{
	double s = getPerimeter() / 2.0;
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

// Return the perimeter of this circle
double Triangle::getPerimeter() const
{
	return side1+side2+side3;
}

// Didn't let me submit the header file so I have it here instead
/*
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "GeometricObject.h"

class Triangle : public GeometricObject
{
public:
	Triangle();
	Triangle(double s1, double s2, double s3);
	Triangle(double s1, double s2, double s3, const string& color, bool filled);
	double getSide1() const;
	double getSide2() const;
	double getSide3() const;
	double getArea() const;
	double getPerimeter() const;

private:
	double side1;
	double side2;
	double side3;
};

#endif
*/