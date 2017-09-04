#include "stdafx.h"
#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(int x, int y, int width, int height, Color color) :Shape(color), x(x), y(y), width(width), height(height) {

}

Rectangle::Rectangle(const Rectangle& other) : Shape(other), x(other.x), y(other.y), width(other.width), height(other.height) {

}

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

Rectangle::~Rectangle() {
}


std::string Rectangle::toString() const{
	return "rectangle";
}

Shape* Rectangle::clone() const{
	return new Rectangle(*this);
}

void Rectangle::draw(SDL_Renderer &renderer) {
	Color color = getColor();
	SDL_SetRenderDrawColor(&renderer, color.getRed(), color.getGreen(), color.getBlue(), 255);
	SDL_Rect p = { x,y,x + width,y + height };
	SDL_RenderFillRect(&renderer, &p);
}