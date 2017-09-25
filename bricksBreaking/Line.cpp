#include "stdafx.h"
#include "Line.h"
#include <algorithm>
#include <iostream>
#include <sstream>

namespace Physics {

	//Constructs the line that goes between two given points
	Line::Line(Point a, Point b) :vert(a.getX() == b.getX()), m(calcM(a, b)), n(calcN(a, b)), a(a), b(b) {

	}

	//Deep copies an existing line object
	Line::Line(const Line& other) : vert(other.vert), m(other.m), n(other.n), a(other.a), b(other.b) {

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
		if (!vert) {
			//calculates the distance using the equation d = |(m*x0-y0+n)/sqrt(m^2+1)|
			return abs((m*point.getX() - point.getY() + n) / sqrt(pow(m, 2) + 1));
		}
		else {
			//calculates the distance using the equation d = |x0-x(line)|
			return abs(point.getX() - getX());
		}
	}

	Vector Line::getVector() {
		return Vector::getVectorCartesian(1, m);
	}

	//calculates the m (y=mx+n) of the line that goes from point a to point b
	double Line::calcM(Point a, Point b) {
		//Finding m from the equation m=(y2-y1)/(x2-x1)
		if (vert)	return INFINITY;
		double m = double(b.getY() - a.getY()) / double(b.getX() - a.getX());
		return m;
	}

	//calculates the n (y=mx+n) of the line that goes from point a to point b
	double Line::calcN(Point a, Point b) {
		//Finding n from the equation n=(x2*y1-y2*x1)/(x2-x1)
		if (vert)	return NAN;
		return ((b.getX()*a.getY() - b.getY()*a.getX()) / (b.getX() - a.getX()));
	}

	//getter for m
	double Line::getM() const {
		return m;
	}

	//getter for n
	double Line::getN() const {
		return n;
	}

	//getter for vert
	bool Line::isVertical() const {
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
	bool Line::intersect(Line& other) const {
		bool v1 = vert, v2 = other.isVertical();
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
				double min2 = max->minY();
				double max1 = min->maxY();
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

			x = double(n2 - n1) / double(m1 - m2);
		}
		else { //one line isn't vertical
			double y;
			const Line* ver; //The vertical line
			const Line* nonVer; //The non-vertical line
			if (v1) { //this line is vertical
				ver = this;
				nonVer = &other;
			}
			else { //the other line is vertical
				ver = &other;
				nonVer = this;
			}
			x = ver->getX();
			y = nonVer->getY(x);
			return ver->isOnLineY(y) && nonVer->isOnLineX(x);
		}
		return isOnLineX(x) && other.isOnLineX(x);
	}

	//check intersection with circle
	bool Line::intersect(Point center, double radius) {
		double dist = distFromPoint(center);
		if (dist > radius) {
			return false; //the distance between the line and the circle is greater than the radius.
		}
		else { //the distance between the line and the circle is smaller than or equal to the radius
			double x0 = center.getX();
			double y0 = center.getY();
			if (!vert) {
				double del = -pow(n, 2) - 2 * n*x0*m + 2 * n*y0 - pow(x0*m, 2) + 2 * x0*y0*m - pow(y0, 2) + pow(m*radius, 2) + pow(radius, 2);
				del = sqrt(del);
				std::pair<double, double> segCircle;
				segCircle.first = (-del - n*m + x0 + y0*m) / (pow(m, 2) + 1);
				segCircle.second = (del - n*m + x0 + y0*m) / (pow(m, 2) + 1);
				//std::cout << "(" << segCircle.first << " , " << segCircle.second << ")" << std::endl;
				std::pair<double, double> segLine;
				segLine.first = std::min(a.getX(), b.getX());
				segLine.second = std::max(a.getX(), b.getX());
				std::pair<double, double> *segMin; //the leftmost segment
				std::pair<double, double> *segMax; //the rightmost segment
				if (segCircle.first <= segLine.first) {
					segMin = &segCircle;
					segMax = &segLine;
				}
				else {
					segMin = &segLine;
					segMax = &segCircle;
				}
				return segMin->second >= segMax->first;
			}
			else {
				double del = pow(radius, 2) - pow(getX() - x0, 2);
				del = sqrt(del);
				std::pair<double, double> segCircle;
				std::pair<double, double> segLine;
				segCircle.first = y0 - del;
				segCircle.second = y0 + del;
				segLine.first = minY();
				segLine.second = maxY();
				std::pair<double, double>* segMin;
				std::pair<double, double>* segMax;
				if (segCircle.first < segLine.first) {
					segMin = &segCircle;
					segMax = &segLine;
				}
				else {
					segMin = &segLine;
					segMax = &segCircle;
				}
				return segMin->second > segMax->first;
			}
		}
	}

	bool Line::isOnLineX(double x) const {
		if (vert) {
			throw std::exception("Can't call this method on a vertical line");
		}
		else {
			double minX = std::min(a.getX(), b.getX());
			double maxX = std::max(a.getX(), b.getX());
			return x >= minX && x <= maxX;
		}
	}

	bool Line::isOnLineY(double y) const {
		if (!vert) {
			throw std::exception("Can't call this method on a non-vertical line");
		}
		else {
			double minY = std::min(a.getY(), b.getY());
			double maxY = std::max(a.getY(), b.getY());
			return y >= minY && y <= maxY;
		}
	}

	double Line::getY(double x) const {
		if (vert) {
			throw std::exception("Can't call this method on a vertical line");
		}
		else {
			return m*x + n;
		}
	}

	//operator << overload
	std::ostream& operator<<(std::ostream& os, const Line& line) {
		os << "y=" << line.m << "x+" << line.n << " a:" << line.a << " b:" << line.b;
		return os;
	}
}