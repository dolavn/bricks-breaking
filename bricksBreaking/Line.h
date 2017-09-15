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
		/**
			Returns the slope of this line, that is, the m in the equation y=mx+n.

			@return The slope of this line
		*/
		double getM();
		/**
			Returns the n in the equation y=mx+n for this line.

			@return The n in the equation y=mx+n for this line.
		*/
		double getN();
		/**
			Returns true if and only if this line is vertical, that is x=x0.

			@return True if and only if, this line is vertical.
		*/
		bool isVertical();
	private:
		double calcM(Point a, Point b);
		double calcN(Point a, Point b);
		bool vert;
		double m;
		double n;
		Point a;
		Point b;
	};
}

#endif