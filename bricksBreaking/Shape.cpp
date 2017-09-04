#include "stdafx.h"
#include "Shape.h"

#include <iostream>

Shape::Shape(Color color) :color(color), id(rand()%10000) {
}

Shape::Shape(const Shape& other) : color(other.color),id(rand()%10000) {
}

Shape::~Shape() {
}

Shape& Shape::operator=(const Shape& other) {
	if (&other==this)
		return *this;
	else
		color = other.color;
	return *this;
}

Color Shape::getColor() const {
	return color;
}

int Shape::getId() const {
	return id;
}