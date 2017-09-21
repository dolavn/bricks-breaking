#include "Point.h"
#include "Vector.h"

#ifndef LINE_H_
#define LINE_H_

namespace Physics {
	/**
		A line in the cartesian plane, defined by the equation y=mx+n,
		and two points which define the bounderies of the line.

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
		double getM() const;
		/**
			Returns the n in the equation y=mx+n for this line.

			@return The n in the equation y=mx+n for this line.
		*/
		double getN() const;
		/**
			Returns true if and only if this line is vertical, that is x=x0.

			@return True if and only if, this line is vertical.
		*/
		bool isVertical() const;
		/**
			Returns true if and only if this line, and another intersect.

			@param other The other line.
			@return True if and only if this line and the other intersect.
		*/
		bool intersect(Line& other) const;
		/**
			Returns true if and only if this line and a given circle intersect.

			@param center The center of the circle
			@param radius The radius of the circle

			@return True if and only if this line and the given circle intersect.
		*/
		bool intersect(Point center, double radius);
		/**
			Return the x of this line, if this line is vertical. Otherwise throws 
			an exception.

			@return The x of this line, if this line is vertical.
			@throw std::exception If this line isn't vertical.
		*/
		double getX() const;
		/**
			Returns the maximum y value of this line, if this line is vertical, otherwise throws
			an exception.

			@throw std::exception If this line isn't vertical.
			@return The maximum y value of this line
		*/
		double maxY() const;
		/**
			Returns the minimum y value of this line, if this line is vertical, otherwise throws
			an exception.

			@throw std::exception If this line isn't vertical.
			@return The minimum y value of this line
		*/
		double minY() const;
		/**
			Returns true if and only if a given x value is on the line, can only be used
			on non-vertical lines. Throws an exception when used on vertical lines.

			@param x A given x value.
			@throws std::exception When used on vertical lines.
			@return True if and only if a given x value is on the line.
		*/
		bool isOnLineX(double x) const;
		/**
			Returns true if and only if a given y value is on this line.
			To be used only on vertical lines, throws an exception otherwise.

			@param y The given y value
			@throw std::exception If this isn't a vertical line.
			@return True if and only if this y value
		*/
		bool isOnLineY(double y) const;
		/**
			Returns the y value of the line when x is equal to a given x. Can only call
			this method on a non-vertical line, throws an exception otherwise.

			@param x A given x value
			@throws std::exception If this line is vertical.
			@return The y value of the line when x is equal to the given x
		*/
		double getY(double x) const;
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