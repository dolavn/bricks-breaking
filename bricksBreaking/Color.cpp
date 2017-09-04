#include "stdafx.h"
#include "Color.h"

Color::Color(unsigned char r, unsigned char g, unsigned char b) :r(r), g(g), b(b) {

}

Color::Color(const Color& other) : r(other.r), g(other.g), b(other.b) {

}

Color& Color::operator=(const Color& other) {
	if (&other == this) {
		return *this;
	}
	return Color(*this);
}

unsigned char Color::getRed() const {
	return r;
}

unsigned char Color::getGreen() const {
	return g;
}

unsigned char Color::getBlue() const {
	return b;
}

SDL_Color Color::getColor() const {
	return{ r,g,b,255 };
}