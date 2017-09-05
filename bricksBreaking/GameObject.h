/**
	A GameObject, each object in the game should
	derive from that class. 

	@author Dolav Nitay
	@version 1.0
*/
#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Vector.h"
#include "Shape.h"
#include "Graphics.h"
#include "Observer.h"
#include "Point.h"
#include <vector>

class GameObject {
public:
	/**
		Constructs a new game object, in location (0,0)
	*/
	GameObject();

	/**
		Constructs a new game object, in location (x,y)

		@param x The x coordinate of the game object,
		@param y The y coordinate of the Game object
	*/
	GameObject(int x, int y);

	/**
		Deep copies an existing GameObject object

		@param other The other GameObject object.
	*/
	GameObject(const GameObject& other);

	/**
		An assignment operator, returns a deep copied copy
		of another GameObject.

		@param other The other GameObject object.
		@return A deep copied copy of the other GameObject.
	*/
	GameObject& operator=(const GameObject& other);

	/**
		Destroys this GameObject
	*/
	~GameObject();

	/**
		Draws this GameObject to the screen.

		@param graphics The graphics object with which this object will be drawn.
	*/
	void draw(Graphics& graphics);

	/**
		Returns a pointer to a deep-copied copy of this GameObject

		@returns A pointer to a deep-copied copy of this GameObject
	*/
	virtual GameObject* clone() = 0;

	/**
		Moves the object, this function is called by the game engine 
		every timer cycle, and moves this object according to its current velocity.
	*/
	void move();
protected:

	/**
		Changes the velocity of this gameObject

		@param newVelocity The new velocity of this object.
	*/
	void changeVelocity(Physics::Vector& newVelocity);

	/**
		Adds a shape to this object's shapes list. This shape will be drawn 
		along with all other shapes when the object will be drawn.

		@param shape The shape to add.
		@return The index in which the new shape is stored.
	*/
	int addShape(Shape& shape);
	
	/**
		Removes the shape in the index ind, and adds newShape in its place.

		@param newShape The new shape to be added.
		@param ind The index of the shape to be removed.
	*/
	void changeShape(Shape& newShape, int ind);

	/**
		Removes all the shapes in this object's shapes list.
	*/
	void clearShapes();

	/**
		Changes the visibility of this object.

		@param visible The desired visibility of this object.
	*/
	void changeVisibilty(bool visible);

	/**
		Returns a reference to the shape stored in a certain index.

		@param ind The index of the shape.
		@return A reference to the shape stored in a certain index.
	*/
	Shape& getShape(int ind);

	/**
		Returns the x and y coordinates of the location of this
		gameObject.

		@return The location of this gameObject.
	*/
	Point getLocation();

	/**
		Sets the location of this gameObject.
		
		@param x The desired x coordinate of this gameObject
		@param y The desired y coordinate of this gameObject
	*/
	void setLocation(int x, int y);

	/**
		All additional actions needed to be done each time this object 
		moves are to be implemented here. A pure virtual function.
	*/
	virtual void moveObject() = 0;

	/**
		Returns the velocity of this gameObject

		@return The velocity of this gameObject
	*/
	Physics::Vector& getVelocity() const;
private:
	bool visible; //The visibility of this gameObject.
	Point location; //The location of this gameObject
	/*
	The shapes list of this gameObject. A list of shapes to be drawn 
	when this object's draw function is called. Each object in this list is a pair
	of the shape, and the index of this shape in the graphics object.
	*/
	std::vector<std::pair<Shape*, int>> shapesList;
	Physics::Vector *velocity; //The velocity of this gameObject
};
#endif