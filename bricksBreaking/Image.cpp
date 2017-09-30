#include "stdafx.h"
#include "Image.h"
#include <algorithm>
#include <iostream>
#include <SDL_image.h>

//Constructor
Image::Image(std::string filePath, int x, int y):Shape(Colors::BLACK),texture(NULL),filePath(filePath), x(x), y(y),width(-1),height(-1){
	
}

//Constructor with image's dimensions
Image::Image(std::string filePath, int x, int y, int width, int height) : Shape(Colors::BLACK), texture(NULL), filePath(filePath), x(x), y(y), width(width), height(height) {

}


//Copy constructor
Image::Image(const Image& other) : Shape(other), texture(other.texture),filePath(other.filePath), x(other.x), y(other.y),width(other.width),height(other.height){

}

//Assignment operator
Image& Image::operator=(const Image& other) {
	throw std::exception("Image is an immutable object!");
}


Image::~Image() {

}

void Image::draw(Graphics& graphics) {
	SDL_Renderer& renderer = graphics.getRenderer();
	if (texture == NULL) {
		texture = graphics.getTexture(filePath);
	}
	SDL_Rect viewPort;
	viewPort.x = std::max(0,x);
	viewPort.y = std::max(0,y);
	if (width == -1 && height == -1) {
		viewPort.w = texture->getWidth() / 2;
		viewPort.h = texture->getHeight() / 2;
	}
	else {
		viewPort.w = width;
		viewPort.h = height;
	}
	SDL_RenderSetViewport(&renderer, &viewPort);
	SDL_RenderCopy(&renderer, &texture->getTexture(), NULL, NULL);
}

Shape* Image::clone() const{
	return new Image(*this);
}

std::string Image::toString() const {
	return "image";
}