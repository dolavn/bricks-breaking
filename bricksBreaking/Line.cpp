#include "stdafx.h"
#include "Line.h"
#include <iostream>

using namespace Physics;

//Constructs the line that goes between two given points
Line::Line(Point a, Point b):vert(a.getX()==b.getX()),m(calcM(a,b)),n(calcN(a,b)),a(a),b(b){
	std::cout << a.getX() << std::endl;
	std::cout << b.getX() << std::endl;
	std::cout << vert << std::endl;
	
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
	return ((b.getY() - a.getY()) / (b.getX()) - a.getX());
}

//calculates the n (y=mx+n) of the line that goes from point a to point b
double Line::calcN(Point a, Point b) {
	//Finding n from the equation n=(x2*y1-y2*x1)/(x2-x1)
	if (vert)	return NAN;
	return ((b.getX()*a.getY() - b.getY()*a.getX()) / (b.getX() - a.getX()));
}

//getter for m
double Line::getM() {
	return m;
}

//getter for n
double Line::getN() {
	return n;
}

//getter for vert
bool Line::isVertical() {
	return vert;
}

