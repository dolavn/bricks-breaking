#include "Image.h"

#include <SDL_image.h>

//Constructor
Image::Image(ImageSurface& surface, int x, int y):Shape(Colors::BLACK),surface(surface), x(x), y(y){
	
}

//Initializes the class
void Image::init() {

}