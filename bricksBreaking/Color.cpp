#include "stdafx.h"
#include "Color.h"

//Constructs a new color object.
Color::Color(unsigned char r, unsigned char g, unsigned char b) :r(r), g(g), b(b) {

}

//A copy constructor
Color::Color(const Color& other) : r(other.r), g(other.g), b(other.b) {

}

//Assignment operator
Color& Color::operator=(const Color& other) {
	if (&other == this) {
		return *this;
	}
	return Color(*this);
}

//Getter for the red byte
unsigned char Color::getRed() const {
	return r;
}

//Getter for the green byte
unsigned char Color::getGreen() const {
	return g;
}

//Getter for the blue byte
unsigned char Color::getBlue() const {
	return b;
}

//Returns an SDL_Color object of this color
SDL_Color Color::getColor() const {
	return{ r,g,b,255 };
}