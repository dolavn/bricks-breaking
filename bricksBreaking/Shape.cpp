#include "stdafx.h"
#include "Shape.h"

#include <iostream>

//Constructs a new shape, of color color, with a random id between 0-10000
Shape::Shape(Color color) :color(color), id(rand()%10000) {
}

//Deep copies an existing shape, assigning a new random id between 0-10000
Shape::Shape(const Shape& other) : color(other.color),id(rand()%10000) {
}

//Destructs this shape.
Shape::~Shape() {
}

//Assignment operator
Shape& Shape::operator=(const Shape& other) {
	if (&other==this)
		return *this;
	else
		color = other.color;
	return *this;
}

//Returns the color of this shape.
Color Shape::getColor() const {
	return color;
}

//Returns the id of this shape
int Shape::getId() const {
	return id;
}