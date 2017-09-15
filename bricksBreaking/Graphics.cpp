#include "stdafx.h"
#include "Graphics.h"
#include "Rectangle.h"
#include "Text.h"
#include "Circle.h"
#include <iostream>

//Constructs the graphics engine of the game.
Graphics::Graphics(int width, int height) :width(width), height(height) {
	drawList = new std::vector<Shape*>();
	freeIndexes = std::vector<int>();
	textures = std::vector<ImageTexture*>();
	lock = SDL_CreateMutex();
}

//Destructs the graphics engine object.
Graphics::~Graphics() {
	for (unsigned int i = 0; i < drawList->size(); i++)
		delete((*drawList)[i]);
	for (unsigned int i = 0; i < textures.size(); i++)
		delete(textures[i]);
	delete(drawList);
	SDL_DestroyMutex(lock);
	SDL_DestroyRenderer(renderer);
}

//Initializes the graphics engine,
bool Graphics::init() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { //Attampts ot initialize the SDL class
		return false;
	}
	//Creates the window, the renderer and the surface.
	window = SDL_CreateWindow("Bricks breaking", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	surface = SDL_GetWindowSurface(window);
	viewPort.x = 0;
	viewPort.y = 0;
	viewPort.w = width;
	viewPort.h = height;
	return true;
}

//Draws all the shapes in the shapes vector to the screen.
void Graphics::draw() {
	SDL_Rect bg = { 0,0,width,height };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &bg); //Draws a black rectangle on the window to erase previous frame
	SDL_LockMutex(lock); //Acquires the lock to access the shapes vector
	for (unsigned int i = 0; i < drawList->size(); i++) {
		if ((*drawList)[i] != nullptr) { //The current shape wasn't deleted
			Shape& currShape = *(*drawList)[i];
			currShape.draw(*this); //Draws the shape using the renderer
			SDL_RenderSetViewport(renderer, &viewPort);
		}
	}
	SDL_UnlockMutex(lock); //Releases the lock
}

//Renders the screen
void Graphics::render() {
	SDL_RenderPresent(renderer);
}

//Adds a shape to the shapes vector
int Graphics::addShape(Shape& shape) {
	SDL_LockMutex(lock); //Acquires the lock to access the shapes vector
	Shape* insert = shape.clone(); //clones the shape
	int ans = 0;
	if (freeIndexes.size() == 0) { //There are no free indexes in the shapes vector
		drawList->push_back(insert);
		ans = int(drawList->size() - 1);
	}
	else { //There are free indexes in the shapes vector
		ans = freeIndexes[freeIndexes.size() - 1];
		freeIndexes.pop_back(); //Removes one free index, and inserts the new shape to that index.
		(*drawList)[ans] = insert;
	}
	SDL_UnlockMutex(lock); //Releases the lock
	return ans;
}

//Removes a shape
void Graphics::removeShape(int index) {
	SDL_LockMutex(lock); //Acquires the lock to access the shapes vector
	if (index < drawList->size()) {
		Shape* curr = (*drawList)[index];
		delete(curr); //Frees the memory held by this shape
		(*drawList)[index] = nullptr;
		freeIndexes.push_back(index); //Adds the index from which the shape was deleted to the free indexes list
	}
	SDL_UnlockMutex(lock); //Releases the lock
}

//Returns an image texture for a specific path
ImageTexture* Graphics::getTexture(std::string path) {
	for (unsigned int i = 0; i < textures.size(); i++) { //Checks if this image was already loaded
		if (path == textures[i]->getPath()){
			return textures[i];
		}
	}
	ImageTexture* newTexture = new ImageTexture(path, *renderer); //If this image wasn't loaded yet, loads it.
	textures.push_back(newTexture);
	return newTexture;
}

//A getter for the renderer
SDL_Renderer& Graphics::getRenderer() const {
	return *renderer;
}