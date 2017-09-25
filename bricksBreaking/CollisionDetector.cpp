#include "stdafx.h"
#include "CollisionDetector.h"
#include "CollisionEvent.h"
#include "Line.h"

//constructor
CollisionDetector::CollisionDetector(Observer& obs) :obs(obs) {
}

//destructor
CollisionDetector::~CollisionDetector() {

}

//adds a new collidable 
void CollisionDetector::addCollidable(Collidable* collidable) {
	if (!collidable->isCircle()) {
		//std::vector<Physics::Line> sides = collidable->getSides();
		//std::cout << sides[0] << std::endl;
	}
	collidables.push_back(collidable);
}

void CollisionDetector::detectCollisions() {
	for (unsigned int i = 0; i < collidables.size(); i++) {
		for (unsigned int j = i+1; j < collidables.size(); j++) {
			//std::cout << "(" << i << "," << j << ")" << std::endl;
			if (checkCollision(*(collidables[i]), *(collidables[j]))) {
				obs.notifyEvent(Game::CollisionEvent(*collidables[i], *collidables[j]));
			}
		}
	}
}

//Checks collision between two collidables
bool CollisionDetector::checkCollision(Collidable& colla, Collidable& collb) {
	char flagA = CONVEX_FLAG, flagB = CONVEX_FLAG, flagAnd = 0;
	if (colla.isCircle()) {
		flagA = CIRCLE_FLAG;
	}
	if (collb.isCircle()) {
		flagB = CIRCLE_FLAG;
	}
	flagAnd = flagA & flagB;
	if (colla.isCircle() && collb.isCircle()) {
		return checkCollisionCirc(colla, collb);
	}
	if (!colla.isCircle() && !collb.isCircle()) {
		return checkCollisionConv(colla, collb);
	}
	//std::cout << (int)(flagAnd) << std::endl;   
	return checkCollisionMix(colla, collb);
}

//checks collision between two circles
bool CollisionDetector::checkCollisionCirc(Collidable& colla, Collidable& collb) {
	Point centerA = colla.getCenter();
	Point centerB = collb.getCenter();
	double radiusSum = colla.getRadius() + collb.getRadius();
	return centerA.distFromPoint(centerB) <= radiusSum;
}

//checks collision between two convex shapes
bool CollisionDetector::checkCollisionConv(Collidable& colla, Collidable& collb) {
	std::vector<Physics::Line> linesA = colla.getSides();
	std::vector<Physics::Line> linesB = collb.getSides();
	for (unsigned int i = 0; i < linesA.size(); i++) {
		for (unsigned int j = 0; j < linesB.size(); j++) {
			Physics::Line& currA = linesA[i];
			Physics::Line& currB = linesB[j];
			if (currA.intersect(currB)) {
				return true;
			}
		}
	}
	return false;
}

//checks collision between a circle and a convex
bool CollisionDetector::checkCollisionMix(Collidable& colla, Collidable& collb) {
	Collidable* circle;
	Collidable* convex;
	if (colla.isCircle()) {
		circle = &colla;
		convex = &collb;
	}
	else {
		circle = &collb;
		convex = &colla;
	}
	Point center = circle->getCenter();
	double radius = circle->getRadius();
	std::vector<Physics::Line> sides = convex->getSides();
	if (sides.size() == 1) {
		//std::cout << sides[0] << std::endl;
	}
	for (unsigned int i = 0; i < sides.size(); i++) {
		Physics::Line& curr = sides[i];
		if (curr.intersect(center, radius)) {
			return true;
		}
	}
	return false;
}


