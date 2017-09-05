#include <SDL.h>

#ifndef COLOR_H_
#define COLOR_H_

class Color {
public:
	Color(unsigned char r, unsigned char g, unsigned char b);
	Color(const Color& other);
	Color& operator=(const Color& other);
	unsigned char getRed() const;
	unsigned char getBlue() const;
	unsigned char getGreen() const;
	SDL_Color getColor() const;
private:
	const unsigned char r;
	const unsigned char g;
	const unsigned char b;
};

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

