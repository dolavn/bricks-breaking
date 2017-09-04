/*
	A class which derives from GameObject.
	The moving ball of the game.

	@author Dolav Nitay
	@version 1.0
*/

#include "GameObject.h"
#include "Shape.h"

#ifndef BALL_H_
#define BALL_H_

class Ball :public GameObject {
public:
	/*
		Constructs a new Ball object

		@param x The x coordinate of the ball.
		@param y The y coordinate of the ball.
	*/
	Ball(int x, int y); 

	/*
		Deep copies an existing Ball object

		@param other The other Ball object.
	*/
	Ball(const Ball& other);

	/*
		An assignment operator, returns a deep copied copy
		of another ball.

		@param other The other ball object.
		@returns A deep copied copy of the other ball.
	*/
	Ball& operator=(const Ball& other);

	/*
		Destroys this ball object.
	*/
	virtual ~Ball();

	/*
		Returns a pointer to a copy of this ball object.

		@return A pointer to a copy of this ball object.
	*/
	virtual GameObject* clone();
private:

	const int BALL_RADIUS = 100; //The radius of the ball
	const Color BALL_COLOR = Colors::RED; //The color of the ball.
	
	virtual void moveObject();

	int spriteIndex; //The index in which the shape of the ball is stored.
};

#endif