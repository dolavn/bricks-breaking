/**
	A class which derives from GameObject.
	The moving ball of the game.

	@author Dolav Nitay
	@version 1.0
*/

#include "GameObject.h"
#include "Collidable.h"
#include "Shape.h"

#ifndef BALL_H_
#define BALL_H_

const int BALL_RADIUS = 50; //The radius of the ball
const Color BALL_COLOR = Colors::RED; //The color of the ball.

class Ball :public GameObject,public Collidable {
public:
	/**
		Constructs a new Ball object

		@param x The x coordinate of the ball.
		@param y The y coordinate of the ball.
	*/
	Ball(int x, int y); 
	/**
		Deep copies an existing Ball object

		@param other The other Ball object.
	*/
	Ball(const Ball& other);
	/**
		An assignment operator, returns a deep copied copy
		of another ball.

		@param other The other ball object.
		@return A deep copied copy of the other ball.
	*/
	Ball& operator=(const Ball& other);
	/**
		Destroys this ball object.
	*/
	virtual ~Ball();
	/**
		How the ball reacts to a collision.

		@param other The other collidable
		@param velocity This collidable's velocity prior to the collision
		@param otherVel The other collidable's velocity prior to the collision
	*/
	virtual void collide(Collidable& other, Physics::Vector velocity,Physics::Vector otherVel);
	/**
		Returns the velocity of this Collidable object.

		@return The velocity of this Collidable object.
	*/
	virtual Physics::Vector getColVelocity() const;
	/**
		Returns a pointer to a copy of this ball object.

		@return A pointer to a copy of this ball object.
	*/
	virtual GameObject* clone();
	/**
		Subscribes this ball to the game engine

		@param engine The engine to subscribe to
	*/
	virtual void subscribe(Engine& engine);
	/**
		Sets this ball's velocity

		@param velocity The new ball's velocity
	*/
	void setVelocity(Physics::Vector velocity);

	/**
	Returns a vector, perpendicular to this collidable's surface , for a collidable
	colliding with this collidable from a given point.

	@param otherLoc The location of the other collidable
	@param otherVel The other collidable's velocity
	@return A vector perpendicular to this collidable's surface
	*/
	virtual Physics::Vector getColNormal(Point otherLoc,Physics::Vector otherVel) const;
private:
	
	virtual void moveObject();

	int spriteIndex; //The index in which the shape of the ball is stored.
};

#endif