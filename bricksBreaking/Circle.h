/**
	This class represents the circle shape. It derives from the class Shape.

	@author Dolav Nitay
	@version 1.0
*/

#include "Shape.h"
#include "Point.h"
#include <math.h>
#include <string>
#include <vector>


#ifndef CIRCLE_H_
#define CIRCLE_H_


const double PI = sinh(1) * 2; //Using arcsin to calculate the value of PI


class Circle :public Shape {
public:
	/**
		Constructs a new circle, object.
		
		@param x The x coordinate of the center of the circle.
		@param y The y coordinate of the center of the circle.
		@param radius The radius of the circle.
		@param c The color of the circle.
	*/
	Circle(int x, int y, int radius, Color c);
	/**
		Deep copies an existing circle.

		@param other The other circle to be deep copied from.
	*/
	Circle(const Circle& other);
	/**
		Assignment operator, used to deep copy an existing circle to this one.

		@param other The other rectangle to be deep copied from.
		@return A reference to the rectangle after the copy
	*/
	Circle& operator=(const Circle& other);
	/**
		Destructs this circle object.
	*/
	virtual ~Circle();
	/**
		Draws this circle using an SDL_Renderer
	*/
	void draw(Graphics& graphics);
	/**
		Sets the center of this circle.

		@param x The new x coordinate of the center of this circle.
		@param y The new y coordinate of the center of this circle.
	*/
	void setCenter(int x, int y);
	/**
		Returns the x coordinate of the center of this circle.

		@return The x coordinate of the center of this circle.
	*/
	int getX();
	/**
		Returns a pointer to a clone of this circle.

		@return A pointer to a clone of this circle.
	*/
	virtual Shape* clone() const;
	/**
		Returns a string representation of this circle.

		@return A string representation of this circle.
	*/
	virtual std::string toString() const;
private:
	int x; //The x coordinate of the center of this circle.
	int y; //The y coordinate of the center of this circle.
	int radius; //The radius of this circle.

	/*
		A vector contatining pairs of points, between which the renderer will
		draw lines when renderering this circle.
	*/
	std::vector<std::pair<Point, Point>> lines;

	/**
		Converts an angle from degrees to radians.

		@param angle An angle.
		@return The angle in units of radians.
	*/
	double getRadians(double angle);
	/**
		Initializes this circle.
	*/
	void init();
	/**
		Computes the distance between two points.

		@param a Point a.
		@param b Point b

		@return The distance between point a, and point b.
	*/
	double dist(Point a, Point b);
};

#endif