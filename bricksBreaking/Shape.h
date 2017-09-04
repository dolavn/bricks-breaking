/*
	This class represents a shape, the basic object which 
	can be drawn to the screen using a graphics object.

	@author Dolav Nitay
	@version 1.0
*/
#include <SDL.h>
#include <string>
#include "Color.h"

#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
public:
	/*
		Constructs a new shape of some color

		@param color The color of the shape.
	*/
	Shape(Color color);

	/*
		Deep copies an existing shape to construct a new one.

		@param other The other shape, to be deep copied from.
	*/
	Shape(const Shape& other);

	/*
		Assignment operator, used to deep copy an existing shape to this one.

		@param other The other shape, to be deep copied from.
		@returns A reference to a deep copy of the other shape.
	*/
	Shape& operator=(const Shape& other);

	/*
		Destructs this shape.
	*/
	virtual ~Shape();

	/*
		Draws this shape, using an SDL_Renderer object, a pure virtual function.

		@param renderer The renderer used to render this shape.
	*/
	virtual void draw(SDL_Renderer &renderer)=0;

	/*
		Returns a clone of this shape, a pure virtual function.
		
		@returns A clone of this shape.
	*/
	virtual Shape* clone() const = 0;

	/*
		Returns a string representation of this shape, a pure virtual function.

		@returns A string representation of this shape.
	*/
	virtual std::string toString() const = 0;

	/*
		Returns the id of this shape.

		@returns The id of this shape.
	*/
	int getId() const;
protected:
	/*
		Returns the color of this shape.

		@returns The color of this shape.
	*/
	Color getColor() const;
private:
	const int id; //The id of this shape, a const integer assigned to each shape during construction.
	Color color; //The color of this shape.
};

#endif