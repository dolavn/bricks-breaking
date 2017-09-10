#include "stdafx.h"
#include "Collidable.h"

//constructor for convex polygon
Collidable::Collidable(std::vector<Point>& points,Engine& engine):isCircle(false), sides(),center(0,0),radius(0),engine(engine) {
	setSides(points);
}

//constructor for circle shape
Collidable::Collidable(Point point,double radius,Engine& engine) :isCircle(true), sides(),center(point),radius(radius),engine(engine) {

}

//a getter for the sides of the polygon
std::vector<std::pair<Point, Point>>& Collidable::getSides() {
	return sides;
}

//updates the location of this object
void Collidable::updateLocation(std::vector<Point>& points) {
	if (!isCircle) {
		setSides(points);
	}
	else {
		throw std::exception("Can't call update location on a circular object with a set of points!");
	}
}

//updates the location of this object
void Collidable::updateLocation(Point center) {
	if (isCircle) {
		this->center = center;
	}
	else {
		throw std::exception("Can't call update location on a convex polygon with one point!");
	}
}



//sets the side of this shape
void Collidable::setSides(std::vector<Point>& points) {
	sides = std::vector<std::pair<Point, Point>>();
	for (unsigned int i = 0; i < points.size(); i++) {
		/* Creates a pair of points, between this point and next one.
		The next point is either the point in the next index, or the point in index 0,
		if we've reached the point in the last index. */
		std::pair<Point, Point> curr(points[i], points[(i + 1) % points.size()]);
		sides.push_back(curr);
	}
}