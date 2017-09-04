#pragma once

#include "Shape.h"
#include <string>

class Rectangle :public Shape {
public:
	Rectangle(int x, int y, int width, int height, Color color);
	Rectangle(const Rectangle& other);
	Rectangle& operator=(const Rectangle& other);
	virtual ~Rectangle();
	virtual void draw(SDL_Renderer &renderer);
	virtual Shape* clone() const;
	virtual std::string toString() const;
private:
	int x;
	int y;
	int width;
	int height;
};