#include <SDL.h>

#ifndef COLOR_H_
#define COLOR_H_

/**
	Represents the color of each shape which is drawed using
	the graphics engine.

	@author Dolav Nitay
	@version 1.0
*/
class Color {
public:
	/**
		Constructs a new color object, using a three byte representation of the color.

		@param r The red byte.
		@param g The green byte.
		@param b The blue byte.
	*/
	Color(unsigned char r, unsigned char g, unsigned char b);

	/**
		Deep copies an existing Color object.

		@param other The other Color.
	*/
	Color(const Color& other);

	/**
		The assignment operator, returns a deep copied copy of another
		color.

		@param other The other color
		@return A reference to the color after the copy.
	*/
	Color& operator=(const Color& other);

	/**
		Returns the red byte.

		@return The red byte
	*/
	unsigned char getRed() const;

	/**
		Returns the blue byte.

		@return The blue byte
	*/
	unsigned char getBlue() const;

	/**
		Returns the green byte.

		@return The green byte
	*/
	unsigned char getGreen() const;

	/**
		Returns an SDL_Color object, of this color.

		@return An SDL_Color object, of this color.
	*/
	SDL_Color getColor() const;
private:
	const unsigned char r; //The red byte.
	const unsigned char g; //The green byte.
	const unsigned char b; //The blue byte
};

/**
	A namespace for a set of predefined colors.
*/
namespace Colors {
	const Color RED = Color(255, 0, 0);
	const Color BLUE = Color(0, 0, 255);
	const Color GREEN = Color(0, 255, 0);
	const Color ORANGE = Color(255, 155, 0);
	const Color YELLOW = Color(255, 255, 0);
	const Color PURPLE = Color(255, 0, 255);
	const Color BLACK = Color(0, 0, 0);
}

#endif

