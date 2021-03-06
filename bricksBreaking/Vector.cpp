#include "stdafx.h"
#include "Vector.h"
#include "Circle.h"
#include <iostream>
#include <sstream>
#include <math.h>

namespace Physics {

	//Empty constructor creates the zero vector
	Vector::Vector() :x(0), y(0) {
	}

	//Private constructor, creates the vector (x,y)
	Vector::Vector(double x, double y) : x(x), y(y) {
	}

	//Copy constructor
	Vector::Vector(const Vector& other) : x(other.x), y(other.y) {
	}

	//Destructor
	Vector::~Vector() {
	}

	//Returns the vector with the cartesian coordinates (x,y)
	Vector Vector::getVectorCartesian(double x, double y) {
		return Vector(x, y);
	}

	//Returns a string representation of the vector
	std::string Vector::toString() const {
		std::stringstream ss;
		ss << "(" << x << " , " << y << ")";
		return ss.str();
	}

	//Returns a vector of a certain size and angle
	Vector Vector::getVectorPolar(double size, double angle) {
		//Calculates the x and y coordinates of the vector
		double x = size*cos(angle);
		double y = size*sin(angle);
		return Vector(x, y);
	}

	//Returns a vector of size 1
	Vector Vector::getNormal() const {
		double normalizer = sqrt(pow(x, 2) + pow(y, 2));
		return getVectorCartesian(x / normalizer, y / normalizer);
	}

	//Multiplies this vector with a scalar size and returns the result
	Vector Vector::multByScalar(double scalar) const {
		return getVectorCartesian(x*scalar, y*scalar);
	}

	Vector Vector::rotate(double angle) const {
		double x1 = x*cos(angle) + y*sin(angle);
		double y1 = -x*sin(angle) + y*cos(angle);
		return Physics::Vector::getVectorCartesian(x1, y1);
	}

	//Returns a vector that goes from one point to another
	Vector Vector::getVectorPoints(Point a, Point b) {
		double x = b.getX() - a.getX();
		double y = b.getY() - a.getY();
		return Vector(x, y);
	}

	//Returns the dot product of this vector and another one
	double Vector::dotProduct(const Vector& other) const {
		if (getSize() == 0 || other.getSize() == 0) //If one of the vector is the zero vector
			return 0;
		return (x*other.x + y*other.y) / (getSize()*other.getSize()); //Calculates the dot product
	}

	//Returns the x coordinate of this vector
	double Vector::getX() const {
		return x;
	}

	//Returns the y coordinate of this vector
	double Vector::getY() const {
		return y;
	}

	//Returns the size of this vector
	double Vector::getSize() const {
		return sqrt(x*x + y*y);
	}

	//Returns the angle of this vector
	double Vector::getAngle() const {
		double angle = atan(abs(x) / abs(y));
		if (y >= 0 && x<0)	angle = angle + PI / 2;
		if (x < 0 && y < 0)	angle = angle + PI;
		if (x >= 0 && y < 0)	angle = angle + 3 * PI / 2;
		return angle;
	}

	//Returns the angle between this vector and another one
	double Vector::getAngleWith(const Vector& other) const {
		return acos(dotProduct(other)); //The arccos of the dot product is the angle
	}

	//operator== checks equality
	inline bool operator==(const Vector& rhs, const Vector& lhs) {
		return rhs.x == lhs.x && rhs.y == lhs.y;
	}

}


