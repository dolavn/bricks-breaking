#pragma once
#include "Shape.h"
#include "Point.h"
#include <math.h>
#include <string>
#include <vector>

const double PI = sinh(1) * 2;


class Circle :public Shape {
public:
	Circle(int x, int y, int radius, Color c);
	Circle(const Circle& other);
	Circle& operator=(const Circle& other);
	virtual ~Circle();
	void draw(SDL_Renderer& renderer);
	void setCenter(int x, int y);
	int getX();
	virtual Shape* clone() const;
	virtual std::string toString() const;
private:
	int x;
	int y;
	int radius;
	std::vector<std::pair<Point, Point>> lines;
	double getRadians(double angle);
	void init();
	double dist(Point a, Point b);
};