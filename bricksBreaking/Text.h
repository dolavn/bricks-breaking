/**
	This class represents a text to be drawn on the screen,
	it derives from the class Shape.

	@author Dolav Nitay
	@version 1.0
*/
#include "Shape.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

#ifndef TEXT_H_
#define TEXT_H_

class Text :public Shape {
public:
	/**
		Constructs a new text object.

		@param x The x coordinate of the text.
		@param y The y coordinate of the text.
		@param text The text.
		@param color The color of the text.
	*/
	Text(int x, int y, std::string text, Color color);

	/**
		Constructs a new text object, also accepts its size as a parameter.

		@param x The x coordinate of the text.
		@param y The y coordinate of the text.
		@param text The text.
		@param color The color of the text.
	*/
	Text(int x, int y, std::string text, Color color, int size);

	/**
		Deep copies an existing text object.

		@param other The other text objet.
	*/
	Text(const Text& other);

	/**
		Assignment operator, used to deep copy an existing text object to this one.

		@param other The other text to be copied from.
		@return A reference to the text after the copy
	*/
	Text& operator=(const Text& other);

	/**
		Destructs this text object.
	*/
	virtual ~Text();

	/**
		Draws this circle using an SDL_Renderer
	*/
	virtual void draw(SDL_Renderer &renderer);

	/**
		Returns a pointer to a clone of this text object.

		@return A pointer to a clone of this text object.
	*/
	virtual Shape* clone() const;

	/**
		Returns a string representation of this text object.

		@return A string representation of this text object.
	*/
	virtual std::string toString() const;

private:
	int x; //The x coordinate of this text object.
	int y; //The y coordinate of this text object.
	int size; //The size of the text.
	SDL_Surface *textSurface = NULL; //An SDL surface on which the text will be drawn.
	SDL_Texture *mTexture = NULL; //An SDL texture on which the text will be drawn.
	TTF_Font *font = NULL; //The font of the text.
	std::string text; //The text

	/**
		Initializes this text object.

		@param x The x coordinate of this text object.
		@param y The y coordinate of this text object.
		@param text The text.
		@param size The size of the text.
	*/
	void init(int x, int y, std::string text, int size);

	/**
		Creates the SDL_Surface on which the text is drawn.
	*/
	void initSurface();
};

#endif