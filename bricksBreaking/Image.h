#include "Shape.h"
#include "ImageSurface.h"

#include <string>
#include <SDL.h>

#ifndef IMAGE_H_
#define IMAGE_H_

/**
	This class represents an image that can be drawed to the screen.

	@author Dolav Nitay
	@version 1.0
*/
class Image :public Shape {
public:
	/**
		Regular constructor, creates a new Image object.

		@param filePath The path to the image path
		@param x The x coordinate of the image
		@param y The y coordinate of the image
	*/
	Image(ImageSurface& surface,int x,int y);
	/**
		Copy constructor, deep copies an existing Image object.

		@param other The other image
	*/
	Image(const Image& other);
	/**
		Assignment operator, returns a reference to a deep copied copy of another image.

		@param other The other image
		@return A reference to a deep copied copy of another image
	*/
	Image& operator=(const Image& other);
	/**
		Destructor, destructs this image object.
	*/
	virtual ~Image();
	/**
		Draws the image to the screen using an SDL_Renderer

		@param renderer The SDL_Renderer used to render the image
	*/
	virtual void draw(SDL_Renderer& renderer);
private:
	ImageSurface& surface;
	int x;
	int y;

	/**
		Initializes this image
	*/
	void init();
};

#endif