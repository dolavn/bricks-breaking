#include "Image.h"

#include <SDL_image.h>

//Constructor
Image::Image(std::string filePath, int x, int y) :filePath(filePath), x(x), y(y) {
	
}

//Initializes the class
void Image::init() {
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		throw std::exception("Can't initialize SDL_Image");
	}
	else {

	}
}