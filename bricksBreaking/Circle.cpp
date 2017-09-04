#include "stdafx.h"
#include "Circle.h"
#include <iostream>
#include <sstream>

Circle::Circle(int x, int y, int radius, Color c) :Shape(c), x(x), y(y), radius(radius) {
	init();
}

Circle::Circle(const Circle& other):Shape(other),x(other.x),y(other.y),radius(radius) {
	lines = std::vector<std::pair<Point, Point>>();
	for (unsigned i = 0; i < other.lines.size(); i++) {
		lines.push_back(other.lines[i]);
	}
}

Circle& Circle::operator=(const Circle& other) {
	if (&other == this) {
		return *this;
	}
	x = other.x;
	y = other.y;
	radius = other.radius;
	lines = std::vector<std::pair<Point, Point>>();
	for (unsigned i = 0; i < other.lines.size(); i++) {
		lines.push_back(other.lines[i]);
	}
	return *this;
}

Circle::~Circle() {

}

std::string Circle::toString() const{
	std::stringstream ss;
	ss << "circle (" << x << " , " << y << ")";
	return ss.str();
}

Shape* Circle::clone() const{
	return new Circle(*this);
}


void Circle::draw(SDL_Renderer& renderer) {
	Color color = getColor();
	SDL_SetRenderDrawColor(&renderer,color.getRed(), color.getGreen(), color.getBlue(), 255);
	for (unsigned int i = 0; i < lines.size(); i = i + 1) {
		int x1 = lines[i].first.getX();
		int y1 = lines[i].first.getY();
		int x2 = lines[i].second.getX();
		int y2 = lines[i].second.getY();
		SDL_RenderDrawLine(&renderer, x1, y1, x2, y2);
	}
}

double Circle::getRadians(double angle) {
	return ((angle / 180)*PI);
}

void Circle::init() {
	lines = std::vector<std::pair<Point, Point>>();
	for (int a = 0; a < 2 * radius; a = a + 1) {
		int currY = this->y + radius - a;
		int diff = int(sqrt(2*a*radius - pow(a, 2)));
		int x1 = this->x - diff;
		int x2 = this->x + diff;
		Point p1 = Point(x1, currY);
		Point p2 = Point(x2, currY);
		std::pair<Point, Point> currPair = std::pair<Point, Point>(p1, p2);
		lines.push_back(currPair);
	}
}

double Circle::dist(Point a, Point b) {
	int x1 = a.getX();
	int x2 = b.getX();
	int y1 = a.getY();
	int y2 = b.getY();
	double ans= sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return ans;
}

void Circle::setCenter(int x, int y) {
	int dx = x - this->x;
	int dy = y - this->y;
	this->x = this->x + dx;
	this->y = this->y + dy;
	for (unsigned int i = 0; i < lines.size(); i = i + 1) {
		Point& p1 = lines[i].first;
		Point& p2 = lines[i].second;
		p1 = Point(p1.getX() + dx, p1.getY() + dy);
		p2 = Point(p2.getX() + dx, p2.getY() + dy);
	}
}

int Circle::getX() {
	return x;
}