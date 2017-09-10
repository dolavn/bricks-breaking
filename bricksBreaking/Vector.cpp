#include "stdafx.h"
#include "Vector.h"
#include <iostream>
#include <sstream>
#include <math.h>

using namespace Physics;

//Empty constructor creates the zero vector
Vector::Vector():x(0),y(0){
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
	return (x*other.x + y*other.y) /( getSize()*other.getSize()); //Calculates the dot product
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
	return atan(x / y);
}

//Returns the angle between this vector and another one
double Vector::getAngleWith(const Vector& other) const {
	return acos(dotProduct(other)); //The arccos of the dot product is the angle
}


