#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include "Shape.h"

/**
	The graphics engine of the game.
	This class handles drawing and rendering every frame of the game.

	@author Dolav Nitay
	@version 1.0
*/
class Graphics {
public:
	/**
		Constructs a new Graphics object.

		@param width The width of the window
		@param height The height of the window
	*/
	Graphics(int width,int height);

	/**
		A destructor for the graphics.
	*/
	~Graphics();

	/**
		Draws all the shapes in the shapes vector to the screen.
	*/
	void draw();

	/**
		Renders all the shapes that were drawn to the screen
	*/
	void render();

	/**
		Adds a new shape to be drawn by the graphics engine.

		@param shape The new shape to be added.
		@return The index in the shapes vector in which the shape is now stored
	*/
	int addShape(Shape& shape);

	/**
		Removes a shape from a certain index in the shapes vector.

		@param The index in which the shape will be deleted.
	*/
	void removeShape(int index);

	/**
		Initializes the graphics engine, and creates the window in which
		the graphics engine will draw and render.

		@return True if and only if the initilization was successful.
	*/
	bool init();
private:
	int width; //The width of the window
	int height; //The height of the window
	std::vector<Shape*> *drawList; //A vector all the shapes to be drawn
	std::vector<int> freeIndexes; //A vector of all the available indexes in the shapes vector
	SDL_Window *window; //The window
	SDL_Renderer *renderer; //The renderer
	SDL_Surface *surface; //The surface
	SDL_mutex *lock; //A lock for synchronizing operations by multiple threads
	bool running; //True if and only if the engine is working
};

#endif