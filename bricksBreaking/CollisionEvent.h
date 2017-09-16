#include "Event.h"
#include "Collidable.h"

#ifndef COLLISIONEVENT_H_
#define COLLISIONEVENT_H_
/**
	collisionEvent heirs from Event and describes a collision 
	between two collidable object in the game.
*/
namespace Game {
	class CollisionEvent :public Event {
	public:
		CollisionEvent(const CollisionEvent& other);
		CollisionEvent(Collidable& obj1, Collidable& obj2);
		virtual ~CollisionEvent();
		CollisionEvent* clone();
		void handle();
	private:
		Collidable& object1;
		Collidable& object2;
	};
}

#endif
