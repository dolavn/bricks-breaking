#include "stdafx.h"
#include "CollidableLine.h"
#include "LineShape.h"
#include "Rectangle.h"

using namespace Physics;

CollidableLine::CollidableLine(Point a, Point b) :GameObject((a.getX()+b.getX())/2,(a.getY()+b.getY())/2),Collidable(getVector(a,b)) {
	Shapes::Line line = Shapes::Line(a, b, Colors::RED);
	addShape(line);
}

CollidableLine::CollidableLine(const CollidableLine& other) : Collidable(other),GameObject(other) {

}

CollidableLine::~CollidableLine() {
	delete(points);
}

void CollidableLine::collide(Collidable& other, Physics::Vector otherVel) {

}

Physics::Vector CollidableLine::getColVelocity() const{
	return Physics::Vector::getVectorCartesian(0, 0);
}

std::vector<Point>& CollidableLine::getVector(Point a, Point b) {
	points = new std::vector<Point>();
	points->push_back(a);
	points->push_back(b);
	return *points;
}

//clone
GameObject* CollidableLine::clone() {
	return new CollidableLine(*this);
}

//subscribes this game object to the game
void CollidableLine::subscribe(Engine& engine) {
	engine.addCollidable(this);
}

void CollidableLine::moveObject() {
}