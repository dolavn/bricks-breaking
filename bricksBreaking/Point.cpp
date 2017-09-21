#include "stdafx.h"
#include "Point.h"


//A constructor
Point::Point(int x, int y) :x(x), y(y) {

}

//A copy constructor
Point::Point(const Point& other) : x(other.x), y(other.y) {

}

//Assignment operator
Point& Point::operator=(const Point& other) {
	if (&other == this) {
		return *this;
	}
	else {
		x = other.x;
		y = other.y;
		return *this;
	}
}

//Getter for x
int Point::getX() const{
	return x;
}

//Getter for y
int Point::getY() const{
	return y;
}

//calculates the distance between this point and another
double Point::distFromPoint(const Point& other) const {
	return sqrt(pow(other.x - x, 2) + pow(other.y - y, 2));
}

//operator << overload
std::ostream& operator<<(std::ostream& os, const Point& point) {
	os << "(" << point.x << "," << point.y << ")";
	return os;
}