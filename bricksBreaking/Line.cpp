#include "stdafx.h"
#include "Line.h"
#include <algorithm>
#include <iostream>

using namespace Physics;

//Constructs the line that goes between two given points
Line::Line(Point a, Point b):vert(a.getX()==b.getX()),m(calcM(a,b)),n(calcN(a,b)),a(a),b(b){
}

//Deep copies an existing line object
Line::Line(const Line& other) :vert(other.vert), m(other.m), n(other.n),a(other.a),b(other.b){

}

//Assignment operator
Line& Line::operator=(const Line& other) {
	if (&other == this) {
		return *this;
	}
	else {
		m = other.m;
		n = other.n;
		return *this;
	}
}

//destructor
Line::~Line() {

}

//calculates the distance between this line and a given point
double Line::distFromPoint(const Point& point) {
	//calculates the distance using the equation d = |(m*x0-y0+n)/sqrt(m^2+1)|
	return abs((m*point.getX() - point.getY() + n) / sqrt(pow(m, 2) + 1));
}

Vector Line::getVector() {
	return Vector::getVectorCartesian(1, m);
}

//calculates the m (y=mx+n) of the line that goes from point a to point b
double Line::calcM(Point a, Point b) {
	//Finding m from the equation m=(y2-y1)/(x2-x1)
	if (vert)	return INFINITY;
	return ((double(b.getY() - a.getY())) / double(b.getX()) - a.getX());
}

//calculates the n (y=mx+n) of the line that goes from point a to point b
double Line::calcN(Point a, Point b) {
	//Finding n from the equation n=(x2*y1-y2*x1)/(x2-x1)
	if (vert)	return NAN;
	return ((b.getX()*a.getY() - b.getY()*a.getX()) / (b.getX() - a.getX()));
}

//getter for m
double Line::getM() const{
	return m;
}

//getter for n
double Line::getN() const{
	return n;
}

//getter for vert
bool Line::isVertical() const{
	return vert;
}

//getter for the x value of this line
double Line::getX() const {
	if (!vert) {
		throw std::exception("Can only use getX() method on a vertical line.");
	}
	else {
		return a.getX();
	}
}

//getter for maximum y value
double Line::maxY() const {
	if (!vert) {
		throw std::exception("Can only call this method on a vertical line!");
	}
	else {
		double y1 = a.getY();
		double y2 = b.getY();
		return std::max(y1, y2);
	}
}

//getter for minimum y value
double Line::minY() const {
	if (!vert) {
		throw std::exception("Can only call this method on a vertical line!");
	}
	else {
		double y1 = a.getY();
		double y2 = b.getY();
		return std::min(y1, y2);
	}
}

//check intersection with other line
bool Line::intersect(Line& other) const{
	bool v1 = vert ,v2 = other.isVertical();
	if (v1&&v2) { //Both line are verticals
		if (getX() == other.getX()) { //both lines have the same x value
			const Line * min; //The line with smallest minimum y value.
			const Line * max; //The line with largest minimum y value.
			if (minY() < other.minY()) {
				min = this;
				max = &other;
			}
			else {
				min = &other;
				max = this;
			}
			double min1 = min->minY();
			double min2 = max->minY();
			double max1 = min->maxY();
			double max2 = max->maxY();
			return min2 <= max1;
		}
		else { //each line has a different x value
			return false;
		}
	}
	double x; //The x value of the intersection point of the two lines
	if (!v1 && !v2) { //both line aren't vertical
		/*
		Finds the x value of the intersection point by solving for x the equation:
		m1*x+n1=m2*x+n2
		*/
		double m1 = m;
		double m2 = other.getM();
		double n1 = n;
		double n2 = other.getN();

		std::cout << "y=";
		std::cout << m1;
		std::cout << "x+";
		std::cout << n1 << std::endl;
		std::cout << "y=";
		std::cout << m2;
		std::cout << "x+";
		std::cout << n2 << std::endl;
		x = (n2 - n1) / (m1 - m2);
		std::cout << "x:";
		std::cout << x << std::endl;
	}
	else { //one line isn't vertical
		if (v1) { //this line is vertical
			x = getX();
		}
		else { //the other line is vertical
			x = other.getX();
		}
	}
	return isOnLine(x) && other.isOnLine(x);
}

//check intersection with circle
bool Line::intersect(Point center, double radius) {
	double dist = distFromPoint(center);
	return dist <= radius;
}

bool Line::isOnLine(double x) const{
	if (vert) {
		throw std::exception("Can't call this method on a vertical line");
	}
	else {
		double minX = std::min(a.getX(), b.getX());
		double maxX = std::max(a.getX(), b.getX());
		return x >= minX && x <= maxX;
	}
}