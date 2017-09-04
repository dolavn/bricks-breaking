#pragma once

#include <SDL.h>
#include <string>
#include "Color.h"

class Shape {
public:
	Shape(Color color);
	Shape(const Shape& other);
	Shape& operator=(const Shape& other);
	virtual ~Shape();
	virtual void draw(SDL_Renderer &renderer)=0;
	virtual Shape* clone() const = 0;
	virtual std::string toString() const = 0;
	int getId() const;
protected:
	Color getColor() const;
private:
	const int id;
	Color color;
};