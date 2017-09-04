#include "stdafx.h"
#include "GameObject.h"
#include "Circle.h"
#include <iostream>

//An empty constructor
GameObject::GameObject():visible(),location(0,0),velocity(),shapesList(){

}


GameObject::GameObject(int x, int y) : velocity(), location(x, y),shapesList(){

}

GameObject::GameObject(const GameObject& other) : visible(other.visible),location(other.location),velocity(new Physics::Vector(*other.velocity)),shapesList() {
	for (unsigned int i = 0; i < other.shapesList.size(); i = i + 1) {
		std::pair<Shape*, int> currPair = other.shapesList[i];
		std::pair<Shape*, int> newPair;
		newPair.first = currPair.first->clone();
		newPair.second = currPair.second;
		shapesList.push_back(newPair);
	}
}

GameObject& GameObject::operator=(const GameObject& other) {
	if (&other == this) {
		return *this;
	}
	else {
		delete(velocity);
		velocity = new Physics::Vector(other.getVelocity());
		for (unsigned int i = 0; i < shapesList.size(); i = i + 1) {
			std::pair<Shape*, int>& currPair = shapesList[i];
			if (currPair.first != nullptr) {
				delete(currPair.first);
				currPair.first = nullptr;
			}
		}
		while (shapesList.size() > 0) {
			shapesList.pop_back();
		}
		for (unsigned int i = 0; i < other.shapesList.size(); i = i + 1) {
			std::pair<Shape*, int> currPair = other.shapesList[i];
			std::pair<Shape*, int> newPair;
			newPair.first = currPair.first->clone();
			newPair.second = currPair.second;
			shapesList.push_back(newPair);
		}
		return *this;
	}
}

Physics::Vector& GameObject::getVelocity() const{
	return *velocity;
}

void GameObject::changeVelocity(Physics::Vector& velocity) {
	Physics::Vector* newVelocity = new Physics::Vector(velocity);
	delete(this->velocity);
	this->velocity = newVelocity;
}

void GameObject::draw(Graphics& graphics) {
	for (unsigned int i = 0; i < shapesList.size(); i = i + 1) {
		std::pair<Shape*, int>& currPair = shapesList[i];
		if (currPair.first == nullptr) {
			int ind = currPair.second;
			graphics.removeShape(ind);
		}
		else {
			int ind = currPair.second;
			if (ind != -1) {
				graphics.removeShape(ind);
			}
			ind = graphics.addShape(*currPair.first);
			currPair.second = ind;
		}
	}
}

int GameObject::addShape(Shape& shape) {
	Shape* shapePointer = shape.clone();
	std::pair<Shape*, int> newPair = std::pair<Shape*, int>(shapePointer, -1);
	shapesList.push_back(newPair);
	return shapesList.size() - 1;
}

void GameObject::changeShape(Shape & shape, int ind) {
	Shape* shapePointer = shape.clone();
	std::pair<Shape*, int>& currPair = shapesList[ind];
	delete(currPair.first);
	currPair.first = shapePointer;
}

Shape& GameObject::getShape(int ind) {
	return *(shapesList[ind].first);
}

void GameObject::changeVisibilty(bool visibile) {
	this->visible = visible;
}

Point GameObject::getLocation() {
	return location;
}

void GameObject::setLocation(int x,int y) {
	location = Point(x, y);
}

void GameObject::move() {
	int dx = int(this->velocity->getX());
	int dy = int(this->velocity->getY());
	int newX = (location.getX() + dx)%1000;
	int newY = location.getY() + dy;
	location = Point(newX, newY);
	moveObject();
}

void GameObject::clearShapes() {
	for (unsigned int i = 0; i < shapesList.size(); i = i + 1) {
		std::pair<Shape*, int>& currPair = shapesList[i];
		if (currPair.first != nullptr) {
			delete(currPair.first);
			currPair.first = nullptr;
		}
	}
}

GameObject::~GameObject() {
	clearShapes();
	if (velocity != nullptr) {
		delete(velocity);
		velocity = nullptr;
	}
}