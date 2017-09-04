#include "stdafx.h"
#include "Point.h"

Point::Point(int x, int y) :x(x), y(y) {

}

Point::Point(const Point& other) : x(other.x), y(other.y) {

}

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

int Point::getX() const{
	return x;
}

int Point::getY() const{
	return y;
}