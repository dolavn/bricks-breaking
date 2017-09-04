#include "stdafx.h"
#include "Graphics.h"
#include "Rectangle.h"
#include "Text.h"
#include "Circle.h"
#include <iostream>

/*
Constructs the graphics engine of the game.
*/
Graphics::Graphics(int width,int height):width(width),height(height) {
	drawList = new std::vector<Shape*>();
	freeIndexes = std::vector<int>();
	lock = SDL_CreateMutex();
}

/*
Destructs the graphics engine object.
*/
Graphics::~Graphics() {
	for (unsigned int i = 0; i < drawList->size(); i++)
		delete((*drawList)[i]);
	delete(drawList);
	SDL_DestroyMutex(lock);
	SDL_DestroyRenderer(renderer);
}

/*
Initializes the graphics engine,
creates a window of size Width X Height.
creates the surface and the renderer.
*/
bool Graphics::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	window = SDL_CreateWindow("Bricks breaking", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	surface = SDL_GetWindowSurface(window);
	return true;
}

/*
Draws all the shapes in the shapes vector to the screen.
*/
void Graphics::draw() {
	SDL_Rect bg = { 0,0,width,height };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &bg);
	SDL_LockMutex(lock);
	for (unsigned int i = 0; i < drawList->size(); i++) {
		if ((*drawList)[i] != nullptr) {
			Shape& currShape = *(*drawList)[i];
			currShape.draw(*renderer);
		}
	}
	SDL_UnlockMutex(lock);
}

/*
Renders the screen
*/
void Graphics::render() {
	SDL_RenderPresent(renderer);
}

/*
Adds a shape to the shapes vector
*/
int Graphics::addShape(Shape& shape) {
	SDL_LockMutex(lock);
	Shape* insert = shape.clone();
	int ans=0;
	if (freeIndexes.size() == 0){
		drawList->push_back(insert);
		ans = drawList->size() - 1;
	}
	else {
		ans = freeIndexes[freeIndexes.size() - 1];
		freeIndexes.pop_back();
		(*drawList)[ans] = insert;
	}
	SDL_UnlockMutex(lock);
	return ans;
}

void Graphics::removeShape(int index) {
	SDL_LockMutex(lock);
	Shape* curr = (*drawList)[index];
	delete(curr);
	(*drawList)[index] = nullptr;
	freeIndexes.push_back(index);
	SDL_UnlockMutex(lock);
}