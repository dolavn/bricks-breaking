#include "stdafx.h"
#include "Ball.h"
#include "Circle.h"
#include "Image.h"

#include <iostream>

//A constructor of a ball object.
Ball::Ball(int x, int y) :GameObject(x, y) {
	//spriteIndex = addShape(Circle(x, y, BALL_RADIUS, BALL_COLOR)); //Adds the shape of the ball to the shapes list.
	spriteIndex = addShape(Image("ball.png", x, y));
	Physics::Vector vec = Physics::Vector::getVectorCartesian(20, 0); //Should be replaced with random velocity.
	changeVelocity(vec); //Sets the velocity.
}

Ball::Ball(const Ball& other) : GameObject(other),spriteIndex(other.spriteIndex) {
}

Ball& Ball::operator=(const Ball& other) {
	if (&other == this) {
		return *this;
	}
	else {
		GameObject::operator=(other);
		return *this;
	}
}

Ball::~Ball() {
}

GameObject* Ball::clone() {
	Ball* newBall = new Ball(*this);
	return newBall;
}

void Ball::moveObject() {
	//Updates the location of the shape of the ball to it's new location.
	//Circle& c = static_cast<Circle&>(getShape(spriteIndex));
	//c.setCenter(getLocation().getX(), getLocation().getY());
	clearShapes();
	spriteIndex = addShape(Image("ball.png", getLocation().getX(), getLocation().getY()));
}

