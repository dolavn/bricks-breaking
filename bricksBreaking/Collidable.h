#include "Point.h"
#include "Vector.h"
#include "Engine.h"
#include "Line.h"
#include <vector>

#ifndef COLLIDABLE_H_
#define COLLIDABLE_H_

class Collidable {
public:
	/**
		Constructs a new collidable object, use this constructor for 
		convex polygon.

		@param points A vector of all the vertices of the polygon. 
	*/
	Collidable(std::vector<Point>& points,Engine& engine);
	/**
		Constructs a new collidable object, use this constructor
		for circles.

		@param point The center of the circle
	*/
	Collidable(Point center,double radius,Engine& engine);
	/**
		Returns all the sides of the polygon, or an empty vector
		if this collidable is a circle.

		@return A vector of pairs of points
	*/
	std::vector<Physics::Line>& getSides();
	/**
		Updates the location of this object, to be used after this object moved.
		This updateLocation method is used for convex polygons.

		@param points The updated set of points
	*/
	void updateLocation(std::vector<Point>& points);
	/**
		Updates the location of this object, to be used after this object moved.
		This updateLocation method is used for circular objects.

		@param center The center of this circle.
	*/
	void updateLocation(Point center);
	/**
		A pure virtual function, how this collidable reacts to the collision.

		@param dir The direction from which the collision came.
	*/
	virtual void collide(Physics::Vector dir) = 0;
private:
	const bool isCircle;
	const double radius;
	Engine& engine;
	Point center;
	std::vector<Physics::Line> sides;

	void setSides(std::vector<Point>& points);
};

#endif