/*
This class represents the rectangle shape. It derives from the class Shape.

@author Dolav Nitay
@version 1.0
*/

#include "Shape.h"
#include <string>

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle :public Shape {
public:
	/*
		Constructs a new Rectangle.

		@param x The x coordinate of the top left corner of the rectangle.
		@param y The y coordinate of the top left corner of the rectangle.
		@param width The width of the rectangle.
		@param height The height of the rectangle.
		@param color The color of the rectangle.
	*/
	Rectangle(int x, int y, int width, int height, Color color);

	/*
		Deep copies an existing rectangle.

		@param other The other rectangle to be deep copied from.
	*/
	Rectangle(const Rectangle& other);

	/*
		Assignment operator, used to deep copy an existing rectangle to this one.

		@param other The other rectangle to be deep copied from.
		@returns A reference to the rectangle after the copy.
	*/
	Rectangle& operator=(const Rectangle& other);

	/*
		Destructor for this circle object.
	*/
	virtual ~Rectangle();

	/*
		Draws this circle using an SDL_Renderer
	*/
	virtual void draw(SDL_Renderer &renderer);

	/*
		Returns a pointer to a clone of this rectangle.

		@returns A pointer to a clone of this rectangle.
	*/
	virtual Shape* clone() const;

	/*
		Returns a string representation of this rectangle.

		@returns A string representation of this rectangle.
	*/
	virtual std::string toString() const;
private:
	int x; //The x coordinate of the top left corner of the rectangle
	int y; //The y coordinate of the top left corner of the rectangle
	int width; //The width of the rectangle
	int height; //The height of the rectangle
};

#endif