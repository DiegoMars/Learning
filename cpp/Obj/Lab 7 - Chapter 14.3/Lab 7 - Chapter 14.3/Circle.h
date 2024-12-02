#ifndef CIRCLE_H
#define CIRCLE_H
#include <string>
using namespace std;

class Circle
{
public:
	Circle();
	Circle(double);
	double getArea() const;
	double getRadius() const;
	void setRadius(double);
	static int getNumberOfObjects();

	// Operator Functions
	bool operator<(const Circle& c2) const;
	bool operator<=(const Circle& c2) const;
	bool operator==(const Circle& c2) const;
	bool operator!=(const Circle& c2) const;
	bool operator>(const Circle& c2) const;
	bool operator>=(const Circle& c2) const;

private:
	double radius;
	static int numberOfObjects;
};

#endif