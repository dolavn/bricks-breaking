#include "Controllable.h"
#include "Engine.h"

#ifndef PLAYER_SURFACE_H_
#define PLAYER_SURFACE_H_

const int SURFACE_WIDTH = 120;
const int SURFACE_HEIGHT = 20;
const int SURFACE_SPEED = 5;
const Color SURFACE_COLOR = Colors::PURPLE;

class PlayerSurface:public GameObject, public Keyboard::Controllable{
public:
	/**
		Creates a new PlayerSurface, and initiates it's position to be x,y.

		@param x The x coordinate of the surface.
		@param y The y coordinate of the surface.
	*/
	PlayerSurface(int x, int y);
	/**
		Deep copies an existing PlayerSurface object.

		@param other The other PlayerSurface object.
	*/
	PlayerSurface(const PlayerSurface& other);
	/**
		Returns a pointer to a deep copied copy of this PlayerSurface

		@return Returns a pointer to a deep copied copy of this PlayerSurface
	*/
	virtual GameObject* clone(); 	//Inherited from GameObject
	/**
		Subscribes this game object to the engine.

		@param engine The engine to subscribe to
	*/
	virtual void subscribe(Engine& engine); //Inherited from GameObject
	/**
		How this PlayerSurface reacts to a key press.

		@param key The key pressed.
	*/
	virtual void react(Keyboard::Key key); //Inherited from Controllable
protected:
	/**
		All additional actions needed to be done each time this object
		moves are to be implemented here. A pure virtual function.
	*/
	virtual void moveObject(); //Inherited from GameObject
};

#endif