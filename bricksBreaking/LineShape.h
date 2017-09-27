#include "Shape.h"
#include "Point.h"
#include "Color.h"
#include "Graphics.h"
#include <string>

#ifndef LINE_SHAPE_H_
#define LINE_SHAPE_H_

namespace Shapes {
	class Line :public Shape {
	public:
		/**
			Constructs a new Line object, that goes between two points.

			@param a The first point
			@param b The second point
		*/
		Line(Point a, Point b,Color color);
		/**
			Copy constructor, deep copies an existing point to this one.
			
			@param other The other line.
		*/
		Line(const Line& other);
		/**
			Assignment operator, used to deep copy an existing line to this one.

			param other The other line, to be deep copied from.
			@return A reference to a deep copy of the other line.
		*/
		Line& operator=(const Line& other);
		/**
			Returns a pointer to a deep copied copy of this shape.

			@return A pointer to a deep copied copy of this shape.
		*/
		virtual Shape* clone() const;
		/**
			Draws this shape, using an SDL_Renderer object, a pure virtual function.

			@param graphics The graphics used to draw the shape.
		*/
		virtual void draw(Graphics& graphics);
		/**
			Returns a string representation of this shape.

			@return A string representation of this shape.
		*/
		virtual std::string toString() const;
	private:
		Point a;
		Point b;
	};
}

#endif