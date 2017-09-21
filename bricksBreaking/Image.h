#include "Shape.h"
#include "ImageTexture.h"

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
	Image(std::string filepath,int x,int y);
	/**
		Regular constructor, creates a new Image object.

		@param filePath The path to the image path
		@param x The x coordinate of the image
		@param y The y coordinate of the image
		@param width The desired width of the image
		@param height The desired height of the image
	*/
	Image(std::string filepath, int x, int y, int width, int height);
	/**
		Copy constructor, deep copies an existing Image object.

		@param other The other image
	*/
	Image(const Image& other);
	/**
		Assignment operator, because image is an immutable object, this function will throw an exception
		when called.

		@param other The other image
		@throw Can't modify an immutable object
	*/
	Image& operator=(const Image& other);
	/**
		Destructor, destructs this image object.
	*/
	virtual ~Image();
	/**
		Draws the image to the screen.

		@param graphics The graphics used to draw the shape.
	*/
	virtual void draw(Graphics& graphics);
	/**
		Returns a pointer to a deep copied copy of this image.

		@return A pointer to a deep copied copy of this image.
	*/
	virtual Shape* clone() const;
	/**
		Returns a string representation of this shape.

		@return A string representation of this shape.
	*/
	virtual std::string toString() const;
private:
	ImageTexture* texture;
	const std::string filePath;
	const int x;
	const int y;
	const int width;
	const int height;
};

#endif