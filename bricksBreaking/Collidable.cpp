#include "stdafx.h"
#include "Collidable.h"

//constructor for convex polygon
Collidable::Collidable(std::vector<Point>& points):circle(false), sides(),center(0,0),radius(0){
	setSides(points);
}

//constructor for circle shape
Collidable::Collidable(Point point,double radius) :circle(true), sides(),center(point),radius(radius){
}

//copy constructor
Collidable::Collidable(const Collidable& other):circle(other.circle),sides(other.sides),center(other.center),radius(other.radius){
}

//a getter for the sides of the polygon
std::vector<Physics::Line>& Collidable::getSides() {
	return sides;
}

//updates the location of this object
void Collidable::updateLocation(std::vector<Point>& points) {
	if (!circle) {
		setSides(points);
	}
	else {
		throw std::exception("Can't call update location on a circular object with a set of points!");
	}
}

//updates the location of this object
void Collidable::updateLocation(Point center) {
	if (circle) {
		this->center = center;
	}
	else {
		throw std::exception("Can't call update location on a convex polygon with one point!");
	}
}



//sets the side of this shape
void Collidable::setSides(std::vector<Point>& points) {
	sides = std::vector<Physics::Line>();
	if (points.size() > 2) { //There is more than one line to be set.
		for (unsigned int i = 0; i < points.size(); i++) {
			/* Creates a pair of points, between this point and next one.
			The next point is either the point in the next index, or the point in index 0,
			if we've reached the point in the last index. */
			Physics::Line curr(points[i], points[(i + 1) % points.size()]);
			sides.push_back(curr);
		}
	}
	else if(points.size()==2) { //This collidable consists only of one line
		sides.push_back(Physics::Line(points[0], points[1]));
	}
	else {
		throw std::exception("why?");
	}
}

bool Collidable::isCircle() {
	return circle;
}

//getter for circle
double Collidable::getRadius() const {
	if (!circle) {
		throw std::exception("Can only call this method on a circle");
	}
	else {
		return radius;
	}
}

//getter for center point
Point Collidable::getCenter() const {
	if (!circle) {
		throw std::exception("Can only call this method on a circle");
	}
	else {
		return center;
	}
}