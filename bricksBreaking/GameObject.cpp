#include "stdafx.h"
#include "GameObject.h"
#include "Circle.h"
#include <iostream>

//An empty constructor
GameObject::GameObject():visible(),location(0,0),velocity(),shapesList(){

}

//Constructor with initial location
GameObject::GameObject(int x, int y) : velocity(), location(x, y),shapesList(){

}

//Copy constructor
GameObject::GameObject(const GameObject& other) : visible(other.visible),location(other.location),velocity(new Physics::Vector(*other.velocity)),shapesList() {
	//Copies all the shapes in the other gameObject's shapes list
	for (unsigned int i = 0; i < other.shapesList.size(); i = i + 1) { 
		std::pair<Shape*, int> currPair = other.shapesList[i];
		std::pair<Shape*, int> newPair;
		newPair.first = currPair.first->clone();
		newPair.second = currPair.second;
		shapesList.push_back(newPair);
	}
}

//Assignment operator
GameObject& GameObject::operator=(const GameObject& other) {
	if (&other == this) {
		return *this;
	}
	else {
		delete(velocity);
		velocity = new Physics::Vector(other.getVelocity());
		//Removes all the shapes in the current shapes list.
		for (unsigned int i = 0; i < shapesList.size(); i = i + 1) {
			std::pair<Shape*, int>& currPair = shapesList[i];
			if (currPair.first != nullptr) {
				delete(currPair.first);
				currPair.first = nullptr;
			}
		}
		//Empties the shapes list.
		while (shapesList.size() > 0) {
			shapesList.pop_back();
		}
		//Copies all the shapes in the other gameObject's shapes list.
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

//Returns the velocity of this game object.
Physics::Vector& GameObject::getVelocity() const{
	return *velocity;
}


//Changes the velocity of this game object.
void GameObject::changeVelocity(Physics::Vector& velocity) {
	Physics::Vector* newVelocity = new Physics::Vector(velocity);
	delete(this->velocity);
	this->velocity = newVelocity;
}

//Draws this object to the screen.
void GameObject::draw(Graphics& graphics) {
	//Goes over all the shapes in the shapes list
	for (unsigned int i = 0; i < shapesList.size(); i = i + 1) {
		std::pair<Shape*, int>& currPair = shapesList[i];
		if (currPair.first == nullptr) { //Checks if the current shape was deleted.
			int ind = currPair.second;
			graphics.removeShape(ind); //Removes the shape from the graphics object.
		}
		else {
			int ind = currPair.second; 
			if (ind != -1) { //This isn't the first time this shape is being drawn.
				graphics.removeShape(ind); //Removes the previous copy of the shape from the graphics object.
			}
			//Adds the new copy of the current shape to the graphics object.
			ind = graphics.addShape(*currPair.first);
			currPair.second = ind; //Saves the index of this shape.
		}
	}
}

//Adds a shape to the shapes list
int GameObject::addShape(Shape& shape) {
	Shape* shapePointer = shape.clone(); //Clones the shape
	/* Adds the new shape to the list, this shape graphics object index will be -1,
	 until it will be added to the graphics object when the draw function will be called.*/
	std::pair<Shape*, int> newPair = std::pair<Shape*, int>(shapePointer, -1); 
	shapesList.push_back(newPair);
	return shapesList.size() - 1; 
}

//Removes the shape from a specific index and adds newShape in its place.
void GameObject::changeShape(Shape & shape, int ind) {
	Shape* shapePointer = shape.clone();
	std::pair<Shape*, int>& currPair = shapesList[ind];
	delete(currPair.first);
	currPair.first = shapePointer;
}

//Returns the shape of a specific index.
Shape& GameObject::getShape(int ind) {
	return *(shapesList[ind].first);
}

//Changes the visibility of this gameObject.
void GameObject::changeVisibilty(bool visibile) {
	this->visible = visible;
}

//Returns the location of this gameObject
Point GameObject::getLocation() {
	return location;
}

//Sets the location of this gameObject.
void GameObject::setLocation(int x,int y) {
	location = Point(x, y);
}

//Moves this gameObject
void GameObject::move() {
	int dx = int(this->velocity->getX()); //The change in the x coordinates.
	int dy = int(this->velocity->getY()); //The change in the y coordinates.
	int newX = (location.getX() + dx)%1000; //TO EDIT
	int newY = location.getY() + dy;
	location = Point(newX, newY); //Updates the location.
	moveObject(); //Calls moveObject for any additional changes to this object during movemnt.
}

//Removes all the shape from the shapes list
void GameObject::clearShapes() {
	for (unsigned int i = 0; i < shapesList.size(); i = i + 1) {
		std::pair<Shape*, int>& currPair = shapesList[i];
		if (currPair.first != nullptr) {
			delete(currPair.first);
			currPair.first = nullptr;
		}
	}
}

//Destroys this gameObject
GameObject::~GameObject() {
	clearShapes(); //Clears the shape
	if (velocity != nullptr) { //Removes the velocity if necessary
		delete(velocity);
		velocity = nullptr;
	}
}