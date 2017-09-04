#include "stdafx.h"
#include "Circle.h"
#include <iostream>
#include <sstream>

//Constructs a new circle object
Circle::Circle(int x, int y, int radius, Color c) :Shape(c), x(x), y(y), radius(radius) {
	init();
}

//Deep copies a circle object
Circle::Circle(const Circle& other):Shape(other),x(other.x),y(other.y),radius(radius) {
	lines = std::vector<std::pair<Point, Point>>();
	for (unsigned i = 0; i < other.lines.size(); i++) { //Deep copies the vector of the other circle lines.
		lines.push_back(other.lines[i]);
	}
}

//Assignment operator
Circle& Circle::operator=(const Circle& other) {
	if (&other == this) {
		return *this;
	}
	x = other.x;
	y = other.y;
	radius = other.radius;
	lines = std::vector<std::pair<Point, Point>>();
	for (unsigned i = 0; i < other.lines.size(); i++) {
		lines.push_back(other.lines[i]); //Deep copies the vector of the other circle's lines.
	}
	return *this;
}

//Destructor
Circle::~Circle() {

}


//Returns a string representation of this circle.
std::string Circle::toString() const{
	std::stringstream ss;
	ss << "circle (" << x << " , " << y << ")";
	return ss.str();
}

//Returns a pointer to a clone of this circle.
Shape* Circle::clone() const{
	return new Circle(*this);
}

//Draws this circle using an SDL_Renderer
void Circle::draw(SDL_Renderer& renderer) {
	Color color = getColor();
	SDL_SetRenderDrawColor(&renderer,color.getRed(), color.getGreen(), color.getBlue(), 255); //Sets the render draw color.
	for (unsigned int i = 0; i < lines.size(); i = i + 1) { //Draws all the lines that make up the circle.
		int x1 = lines[i].first.getX();
		int y1 = lines[i].first.getY();
		int x2 = lines[i].second.getX();
		int y2 = lines[i].second.getY();
		SDL_RenderDrawLine(&renderer, x1, y1, x2, y2);
	}
}

//Converts degrees to radians.
double Circle::getRadians(double angle) {
	return ((angle / 180)*PI);
}

//Initializes this circle object, creating all the lines that make the circle p.
void Circle::init() {
	lines = std::vector<std::pair<Point, Point>>(); 
	/*In this loop, the value a, is the y value of the current line.
	The loop goes over all possible y values in this circle, and creates a horizental line
	whose y value is a, and is x bounderies are the bounderies of the circle for that y value.
	*/
	for (int a = 0; a < 2 * radius; a = a + 1) {
		//Using geometry to find x1 and x2.
		int currY = this->y + radius - a;
		int diff = int(sqrt(2*a*radius - pow(a, 2)));
		int x1 = this->x - diff;
		int x2 = this->x + diff;
		Point p1 = Point(x1, currY);
		Point p2 = Point(x2, currY);
		//Creates the pair of points and adds it to the lines vector.
		std::pair<Point, Point> currPair = std::pair<Point, Point>(p1, p2);
		lines.push_back(currPair);
	}
}

//Calculates the distance between two points
double Circle::dist(Point a, Point b) {
	int x1 = a.getX();
	int x2 = b.getX();
	int y1 = a.getY();
	int y2 = b.getY();
	double ans= sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	return ans;
}

//Sets the center of this circle
void Circle::setCenter(int x, int y) {
	int dx = x - this->x; //The displacement on the x axis.
	int dy = y - this->y; //The displacement on the y axis.
	//Moves the center of the circle according to the displacement in the x and y axis.
	this->x = this->x + dx;
	this->y = this->y + dy;
	//Moves all the lines according to the displacement in the x and y axis.
	for (unsigned int i = 0; i < lines.size(); i = i + 1) { 
		Point& p1 = lines[i].first;
		Point& p2 = lines[i].second;
		p1 = Point(p1.getX() + dx, p1.getY() + dy);
		p2 = Point(p2.getX() + dx, p2.getY() + dy);
	}
}


//Returns the x value of the center of the circle.
int Circle::getX() {
	return x;
}