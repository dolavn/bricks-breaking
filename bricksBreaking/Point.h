#ifndef POINT_H_
#define POINT_H_

#include <iostream>

/**
	Represents a point in the cartesian plane.

	@author Dolav Nitay
	@version 1.0
*/
class Point {
public:
	/**
		Creates a new point.

		@param x The x coordinate of the point
		@param y The y coordinate of the point
	*/
	Point(int x, int y);

	/**
		Deep copies an existing point.

		@param other The other point to be copied from.
	*/
	Point(const Point& other);

	/**
		Assignment operator, used to deep copy an existing point to this one.

		@param other The other point.
		@return A reference to the point after the copy.
	*/
	Point& operator=(const Point& other);

	/**
		Returns the x coordinate of the point.

		@return The x coordinate of the point
	*/
	int getX() const;

	/**
		Returns the y coordinate of the point.

		@return The y coordinate of the point
	*/
	int getY() const;

	friend std::ostream& operator<<(std::ostream& os, const Point& point);
private:
	int x; //The x coordinate of the point.
	int y; //The y coordinate of the point
};

#endif