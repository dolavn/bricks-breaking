#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>

//Constructs a new rectangel
Rectangle::Rectangle(int x, int y, int width, int height, Color color) :Shape(color), x(x), y(y), width(width), height(height) {

}

//Deep copies an existing rectangle
Rectangle::Rectangle(const Rectangle& other) : Shape(other), x(other.x), y(other.y), width(other.width), height(other.height) {

}

//Assignment operator
Rectangle& Rectangle::operator=(const Rectangle& other) {
	if (&other == this) {
		return *this;
	}
	else {
		x = other.x;
		y = other.y;
		width = other.width;
		height = other.height;
		return *this;
	}
}

//Destructs this rectangle
Rectangle::~Rectangle() {
}

//Returns a string representation of this rectangle
std::string Rectangle::toString() const{
	return "rectangle";
}

//Returns a pointer to a clone of this rectangle.
Shape* Rectangle::clone() const{
	return new Rectangle(*this);
}

//Draws this rectangle to the screen using a renderer.
void Rectangle::draw(SDL_Renderer &renderer) {
	Color color = getColor();
	SDL_SetRenderDrawColor(&renderer, color.getRed(), color.getGreen(), color.getBlue(), 255); //Sets the render color.
	SDL_Rect p = { x,y,x + width,y + height };
	SDL_RenderFillRect(&renderer, &p);
}