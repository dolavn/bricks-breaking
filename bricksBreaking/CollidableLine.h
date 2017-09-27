#include "Collidable.h"
#include "Line.h"
#include <vector>

#ifndef COLLIDABLE_LINE_H_
#define COLLIDABLE_LINE_H_

/**
	A line in the game, which other objects in the game can collide with. 
	Invisible, to be used mainly for borders of the game.

	@author Dolav Nitay
	@version 1.0
*/
class CollidableLine: public GameObject,public Collidable {
public:
	/**
		Constructs a new CollidableLine object, which goes from Point a, to Point b.

		@param a The first point
		@param b The second point
	*/
	CollidableLine(Point a, Point b);
	/**
		Copy constructor, used to deep copy an existing CollidableLine object.

		@param other The existing CollidableLine object.
	*/
	CollidableLine(const CollidableLine& other);
	/**
		Destructs this CollidableLine object.
	*/
	virtual ~CollidableLine();
	/**
		Handles collision with another Collidable object.

		@param other The other Collidable object
		@param otherVel The velocity of the other Collidable prior to the collision.
	*/
	virtual void collide(Collidable& other, Physics::Vector otherVel);
	/**
		Returns a pointer to a deep copied copy of this collidable line.

		@return A pointer to a deep copied copy of this collidable line.
	*/
	virtual GameObject* clone();
	/**
		Subscribes this game object to the engine.

		@param engine The engine to subscribe to
	*/
	virtual void subscribe(Engine& engine);
	/**
		Returns the velocity of this Collidable.

		@return The velocity of this Collidable
	*/
	virtual Physics::Vector getColVelocity() const;
protected:
	virtual void moveObject();
private:
	std::vector<Point>* points;
	//Returns a vector containing the points a and b
	std::vector<Point>& getVector(Point a, Point b);
};

#endif