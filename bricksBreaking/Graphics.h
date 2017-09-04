#pragma once
#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include "Shape.h"

/*
This is the graphics engine of the game, 
This class handles drawing and rendering every frame of the game.
*/
class Graphics {
public:
	Graphics(int width,int height);
	~Graphics();
	void draw();
	void render();
	int addShape(Shape& shape);
	void removeShape(int index);
	bool init();
private:
	int width;
	int height;
	std::vector<Shape*> *drawList;
	std::vector<int> freeIndexes;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *surface;
	SDL_mutex *lock;
	bool running;
};

#endif