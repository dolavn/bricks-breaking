#pragma once
#include "Event.h"
#include "Collidable.h"
using namespace Game;

#ifndef COLLISIONEVENT_H_
#define COLLISIONEVENT_H_

class CollisionEvent{
public:
	CollisionEvent();
	CollisionEvent(const CollisionEvent& other);
	CollisionEvent(Collidable& obj1, Collidable& obj2);
	CollisionEvent& operator=(const CollisionEvent& other);
	virtual ~CollisionEvent();
	void handle();
	Event* clone();
private:
	Collidable& object1;
	Collidable& object2;
};

#endif
