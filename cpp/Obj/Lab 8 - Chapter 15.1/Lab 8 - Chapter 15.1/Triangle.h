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
