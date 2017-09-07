#include "ImageTexture.h"
#include <SDL_image.h>

ImageTexture::ImageTexture(std::string path,SDL_Renderer& renderer) :path(path) {
	init(renderer);
}

ImageTexture::ImageTexture(const ImageTexture& other) : path(other.path) {
	throw std::exception("no copy constructor should be called");
}

ImageTexture& ImageTexture::operator=(const ImageTexture& other) {
	throw std::exception("no assignment operator should be called");

}

SDL_Texture& ImageTexture::getTexture() const{
	return *texture;
}

void ImageTexture::init(SDL_Renderer& renderer) {
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) {
		throw std::exception("Unable to initialize SDL_Image");
	}
	SDL_Surface * loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL) {
		throw std::exception("Unable to load image file");
	}
	texture = SDL_CreateTextureFromSurface(&renderer, loadedSurface);
	SDL_FreeSurface(loadedSurface);
}