#include "CollisionEvent.h"
using namespace Game;

CollisionEvent::CollisionEvent(const CollisionEvent& other) : Event(other),object1(other.object1),object2(other.object2){
}

CollisionEvent::CollisionEvent(Collidable& obj1, Collidable& obj2) : object1(obj1),object2(obj2){
}

CollisionEvent::~CollisionEvent() {
}

CollisionEvent* CollisionEvent::clone() {
	return new CollisionEvent(*this);
}

void CollisionEvent::handle() {
	object1.collide(object2);
	object1.collide(object2);
}
