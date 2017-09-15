#include "stdafx.h"
#include "CollisionDetector.h"
#include "CollisionEvent.h"

//constructor
CollisionDetector::CollisionDetector(Observer& obs) :obs(obs) {

}

//destructor
CollisionDetector::~CollisionDetector() {

}

//adds a new collidable 
void CollisionDetector::addCollidable(Collidable* collidable) {
	collidables.push_back(collidable);
}

void CollisionDetector::detectCollisions() {
	for (unsigned int i = 0; i < collidables.size(); i++) {
		for (unsigned int j = i+1; j < collidables.size(); j++) {
			if (checkCollision(*(collidables[i]), *(collidables[j]))) {
				//notify collision
				//TODO after CollisionEvent is ready
			}
		}
	}
}

//Checks collision between two collidables
bool CollisionDetector::checkCollision(Collidable& colla, Collidable& collb) {
	char flagA=CONVEX_FLAG, flagB=CONVEX_FLAG,flagAnd;
	if (colla.isCircle()) {
		flagA = CIRCLE_FLAG;
	}
	if (colla.isCircle()) {
		flagB = CIRCLE_FLAG;
	}
	flagAnd = flagA & flagB;
	if (flagAnd == CIRCLE_FLAG) {
		return checkCollisionCirc(colla, collb);
	}
	if (flagAnd == CONVEX_FLAG) {
		return checkCollisionConv(colla, collb);
	}
	return checkCollisionMix(colla, collb);
}

bool CollisionDetector::checkCollisionCirc(Collidable& colla, Collidable& collb) {
	return false;
}

bool CollisionDetector::checkCollisionConv(Collidable& colla, Collidable& collb) {
	return false;
}


bool CollisionDetector::checkCollisionMix(Collidable& colla, Collidable& collb) {
	return false;
}


