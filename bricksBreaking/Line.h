#include "Point.h"
#include "Vector.h"

#ifndef LINE_H_
#define LINE_H_

namespace Physics {
	/**
		A line in the cartesian plane, defined by the equation y=mx+n.

		@author Dolav Nitay
		@version 1.0

	*/
	class Line {
	public:
		/**
			Constructs a new line, that goes from point a, to point b

			@param a The first point
			@param b The second point
		*/
		Line(Point a, Point b);
		/**
			Constructs a new line, the one that fits to the equation y=mx+n

			@param m The m parameter from the equation y=mx+n
			@param n The n parameter form the equation y=mx+n
		*/
		Line(double m, double n);
		/**
			Copy constructor, deeps copy an existing Line object.

			@param other The other line
		*/
		Line(const Line& other);
		/**
			Assignment operator, used to deep copy an existing Line object to this one.

			@param other The other line object
			@return Returns this Line after the copy
		*/
		Line& operator=(const Line& other);
		/**
			Destructs this line object
		*/
		~Line();
		/**
			Calculates the distance between this line to a given point.

			@param point The point from which the distance should be calculated
			@return The distance between this line and the point
		*/
		double distFromPoint(const Point& point);	
		/**
			Returns a unit vector with the direction of this line.

			@return A unit vector with the direction of this line
		*/
		Physics::Vector getVector();
	private:
		double calcM(Point a, Point b);
		double calcN(Point a, Point b);
		double m;
		double n;
	};
}

#endif