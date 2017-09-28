#include "stdafx.h"
#include "LineShape.h"
#include <iostream>

namespace Shapes {
	Line::Line(Point a, Point b,Color color):Shape(color),a(a),b(b) {

	}

	Line::Line(const Line& other) : Shape(other), a(other.a), b(other.b) {

	}

	Line& Line::operator=(const Line& other) {
		if (this == &other) {
			return *this;
		}
		else {
			a = other.a;
			b = other.b;
			return *this;
		}
	}

	Shape* Line::clone() const{
		return new Line(*this);
	}

	void Line::draw(Graphics& graphics) {
		SDL_Renderer& renderer = graphics.getRenderer();
		Color color = getColor();
		SDL_SetRenderDrawColor(&renderer, color.getRed(), color.getGreen(), color.getBlue(), 255); //Sets the render draw color.
		int x1 = a.getX(), x2 = b.getX(), y1 = a.getY(), y2 = b.getY();
		SDL_RenderDrawLine(&renderer, x1, y1, x2, y2);
	}

	std::string Line::toString() const{
		return "";
	}
}