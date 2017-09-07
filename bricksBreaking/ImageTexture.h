#include <string>
#include <SDL.h>

#ifndef IMAGE_TEXTURE_H_
#define IMAGE_TEXTURE_H_

/**
	A loaded image file, ready to be rendered to the screen.

	@author Dolav Nitay
	@version 1.0
*/
class ImageTexture {
public:
	/**
		Constructs a new ImageSurface objects, loads the image file to
		the program's memory.

		@param path The path to the image file
		@param window The SDL_Window in which the image will be displayed
	*/
	ImageTexture(std::string path,SDL_Renderer& renderer);
	/**
		A copy constructor, deep copies an existing ImageTexture object.

		@param other The other ImageTexture
	*/
	ImageTexture(const ImageTexture& other);
	/**
		Assignment operator, deep copies an existing ImageTexture object
		over this one.

		@param other The other ImageTexture
		@return A reference to the ImageTexture after the copy
	*/
	ImageTexture& operator=(const ImageTexture& other);
	/**
		Destructs this image texture
	*/
	~ImageTexture();
	/**
		Returns the SDL_Texture in which the image is stored.

		@return The SDL_Texture in which the image is stored.
	*/
	SDL_Texture& getTexture() const;
	/**
		Returns the width of the image

		@return The width of the image
	*/
	int getWidth() const;
	/**
		Returns the height of the image

		@return The height of the image
	*/
	int getHeight() const;
	/**
		Returns the file path of this image texture.

		@return The file path of this image texture.
	*/
	std::string getPath() const;
private:
	std::string path; //The path to the file
	SDL_Texture* texture; //The texture in which the image is stored
	void init(SDL_Renderer& renderer); //Initializes the texture
	int width;
	int height;
};

#endif