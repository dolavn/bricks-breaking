#include "stdafx.h"
#include "ImageTexture.h"
#include <iostream>
#include <SDL_image.h>

//constructor
ImageTexture::ImageTexture(std::string path,SDL_Renderer& renderer) :path(path) {
	init(renderer);
}

//copy constructor, shouldn't be called
ImageTexture::ImageTexture(const ImageTexture& other) : path(other.path) {
	throw std::exception("no copy constructor should be called");
}

//assignment operator, shouldn't be called
ImageTexture& ImageTexture::operator=(const ImageTexture& other) {
	throw std::exception("no assignment operator should be called");
}

//destructor
ImageTexture::~ImageTexture() {
	SDL_DestroyTexture(texture);
}

//A getter for the texture
SDL_Texture& ImageTexture::getTexture() const{
	return *texture;
}

//Initializes this texture
void ImageTexture::init(SDL_Renderer& renderer) {
	int imgFlags = IMG_INIT_PNG; 
	if (!(IMG_Init(imgFlags) & imgFlags)) { //Initializes SDL_Image
		throw std::exception("Unable to initialize SDL_Image");
	}
	std::cout << path << std::endl;
	SDL_Surface * loadedSurface = IMG_Load(path.c_str()); //The loaded image surface
	if (loadedSurface == nullptr) {
		throw std::exception("Unable to load image file");
	}
	std::cout << loadedSurface->w << std::endl;
	texture = SDL_CreateTextureFromSurface(&renderer, loadedSurface); //Creates the texture from the surface
	width = loadedSurface->w; //Saves the image dimensions
	height = loadedSurface->h;
	SDL_FreeSurface(loadedSurface); //Frees the memory allocated for the surface.
}

//A getter for the width
int ImageTexture::getWidth() const {
	return width;
}

//A getter for the height
int ImageTexture::getHeight() const {
	return height;
}

//A getter for the file path
std::string ImageTexture::getPath() const {
	return path;
}