#include "stdafx.h"
#include "Image.h"
#include <SDL_image.h>

//Constructor
Image::Image(std::string filePath, int x, int y):Shape(Colors::BLACK),texture(NULL),filePath(filePath), x(x), y(y){
	
}


//Copy constructor
Image::Image(const Image& other) : Shape(other), texture(other.texture),filePath(other.filePath), x(other.x), y(other.y){

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
	viewPort.x = x;
	viewPort.y = y;
	viewPort.w = texture->getWidth()/2;
	viewPort.h = texture->getHeight()/2;
	SDL_RenderSetViewport(&renderer, &viewPort);
	SDL_RenderCopy(&renderer, &texture->getTexture(), NULL, NULL);
}

Shape* Image::clone() const{
	return new Image(*this);
}

std::string Image::toString() const {
	return "image";
}