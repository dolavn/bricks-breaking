#include "stdafx.h"
#include "Ball.h"
#include "Circle.h"
#include "Image.h"
#include <math.h>

#include <iostream>

//A constructor of a ball object.
Ball::Ball(int x, int y) :GameObject(x, y),Collidable(Point(x,y),BALL_RADIUS) {
	//spriteIndex = addShape(Circle(x, y, BALL_RADIUS, BALL_COLOR)); //Adds the shape of the ball to the shapes list.
	spriteIndex = addShape(Image("ball.png", x, y,BALL_RADIUS,BALL_RADIUS));
	Physics::Vector vec = Physics::Vector::getVectorCartesian(20, 0); //Should be replaced with random velocity.
	changeVelocity(vec); //Sets the velocity.
}

Ball::Ball(const Ball& other) : GameObject(other), Collidable(other),spriteIndex(other.spriteIndex) {
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
	updateLocation(getLocation());
	spriteIndex = addShape(Image("ball.png", getLocation().getX(), getLocation().getY(),BALL_RADIUS*2,BALL_RADIUS*2));
}

void Ball::collide(Collidable& other, Physics::Vector otherVel) {
	changeVelocity(otherVel);
}

void Ball::setVelocity(Physics::Vector velocity) {
	changeVelocity(velocity);
}

void Ball::subscribe(Engine& engine) {
	engine.addCollidable(this);
}

Physics::Vector Ball::getColVelocity() const {
	return getVelocity();
}

