#include "Point.h"
#include "Vector.h"
#include "Engine.h"
#include "Line.h"
#include <vector>

#ifndef COLLIDABLE_H_
#define COLLIDABLE_H_

class Engine;

class Collidable {
public:
	/**
		Constructs a new collidable object, use this constructor for 
		convex polygon.

		@param points A vector of all the vertices of the polygon. 
	*/
	Collidable(std::vector<Point>& points);
	/**
		Constructs a new collidable object, use this constructor
		for circles.

		@param point The center of the circle
	*/
	Collidable(Point center,double radius);
	/**
		Copy constructor, deep copies another Collidable object.

		@param other The other Collidable object
	*/
	Collidable(const Collidable& other);
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
		Returns true if and only if this collidable is a circle.

		@return True if and only if this collidable is a circle.
	*/
	bool isCircle();
	/**
		A pure virtual function, how this collidable reacts to the collision.

		@param other The other collidable with which the collision occured.
	*/
	virtual void collide(Collidable& other,Physics::Vector otherVel) = 0;
	/**
		Returns the radius of the circle, if and only if this collidable is a circle.
		Otherwise throws an exception.

		@throws std::exception If this collidable isn't a circle
		@return The radius of the circle.
	*/
	double getRadius() const;
	/**
		Returns the center of the circle, if and only if this collidable is a circle.
		Otherwise throws an exception.

		@throws std::exception If this collidable isn't a circle
		@return The center of the circle.
	*/
	Point getCenter() const;
	/**
		Returns the velocity of this Collidable object, a pure virtual function.

		@return The velocity of this Collidable object.
	*/
	virtual Physics::Vector getColVelocity() const = 0;
	/**
		Returns a vector, perpendicular to this collidable's surface , for a collidable
		colliding with this collidable from a given point.

		@param otherLoc The location of the other collidable
		@return A vector perpendicular to this collidable's surface 
	*/
	virtual Physics::Vector getColNormal(Point otherLoc) const = 0;
private:
	bool circle;
	double radius;
	Point center;
	std::vector<Physics::Line> sides;

	void setSides(std::vector<Point>& points);
};

#endif