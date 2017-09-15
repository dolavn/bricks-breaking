#include "Collidable.h"
#include "Observer.h"
#include <vector>

#ifndef COLLISION_DETECTOR_H_
#define COLLISION_DETECTOR_H_

const char CIRCLE_FLAG = 1;
const char CONVEX_FLAG = 1 << 1;

/**
	This class is tasked with detecting collisions, and reporting them
	to the observer class.

	@author Dolav Nitay
	@version 1.0
*/
class CollisionDetector {
public:
	/**
		Creates a new collision detector object.

		@param obs The observer to which collision events will be reported.
	*/
	CollisionDetector(Observer& obs);
	/**
		Destructs this collision detector object.
	*/
	~CollisionDetector();
	/**
		Detects collision between all the collidables object subscribed
		to this collision detector.
	*/
	void detectCollisions();
	/**
		Adds a new collidable to this collision detector.

		@param collidable The new collidable to be added.
	*/
	void addCollidable(Collidable* collidable);
private:
	Observer& obs;
	bool checkCollision(Collidable& coll1, Collidable& coll2);
	bool checkCollisionCirc(Collidable& coll1, Collidable& coll2);
	bool checkCollisionConv(Collidable& coll1, Collidable& coll2);
	bool checkCollisionMix(Collidable& coll1, Collidable& coll2);
	std::vector<Collidable*> collidables;
};

#endif
