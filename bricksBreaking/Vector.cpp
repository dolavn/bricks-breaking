#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <sstream>
#include <math.h>

using namespace Physics;

Vector::Vector():x(0),y(0){
}

Vector::Vector(double x, double y) : x(x), y(y) {
}

Vector::Vector(const Vector& other) : x(other.x), y(other.y) {
}


Vector::~Vector() {
}

Vector Vector::getVectorCartesian(double x, double y) {
	return Vector(x, y);
}

std::string Vector::toString() const {
	std::stringstream ss;
	ss << "(" << x << " , " << y << ")";
	return ss.str();
}

Vector Vector::getVectorPolar(double size, double angle) {
	double x = size*cos(angle);
	double y = size*sin(angle);
	return Vector(x, y);
}

double Vector::dotProduct(const Vector& other) const {
	if (getSize() == 0 || other.getSize() == 0)
		return 0;
	return (x*other.x + y*other.y) /( getSize()*other.getSize());
}

double Vector::getX() const {
	return x;
}

double Vector::getY() const {
	return y;
}

double Vector::getSize() const {
	return sqrt(x*x + y*y);
}

double Vector::getAngle() const {
	return atan(x / y);
}

double Vector::getAngleWith(const Vector& other) const {
	return acos(dotProduct(other));
}
