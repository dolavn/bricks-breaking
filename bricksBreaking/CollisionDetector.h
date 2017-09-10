#include "Collidable.h"
#include "Observer.h"
#include <vector>

#ifndef COLLISION_DETECTOR_H_
#define COLLISION_DETECTOR_H_

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
	void addCollidable(Collidable& collidable);
private:
	Observer& obs;
	std::vector<Collidable&> collidables;
};

#endif
