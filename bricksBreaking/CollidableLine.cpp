#include "stdafx.h"
#include "CollidableLine.h"

using namespace Physics;

CollidableLine::CollidableLine(Point a, Point b) :Collidable(getVector(a,b)) {

}

CollidableLine::CollidableLine(const CollidableLine& other) : Collidable(other) {

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