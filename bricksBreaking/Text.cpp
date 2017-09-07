#include "stdafx.h"
#include "Text.h"

#include <iostream>

using namespace std;

//Constructs a new text object.
Text::Text(int x, int y, string text, Color color) :Shape(color) {
	init(x, y, text, 72);
}

//Constructs a new text object.
Text::Text(int x, int y, string text, Color color, int size) : Shape(color) {
	init(x, y, text, size);
}

//Copy constructor
Text::Text(const Text& other) : Shape(other), x(other.x), y(other.y), text(other.text), size(other.size) {
	initSurface();
}

//Assignment operator
Text& Text::operator=(const Text& other) {
	if (&other == this) {
		return *this;
	}
	else {
		x = other.x;
		y = other.y;
		text = other.text;
		size = other.size;
		SDL_FreeSurface(textSurface); //Frees the current SDL_Surface
		TTF_CloseFont(font); //Closes the font
		initSurface(); //Creates the new surface
		return *this;
	}
}

//Destructor
Text::~Text() {
	SDL_FreeSurface(textSurface); //Frees the current SDL_Surface
	TTF_CloseFont(font); //Closes the font.
}

//Returns a string representation of this text object.
std::string Text::toString() const{
	return "text";
}

//Initializes this text object.
void Text::init(int x, int y, string text, int size) {
	//Sets all the values of this object.
	this->x = x;
	this->y = y;
	this->text = text;
	this->size = size;
	//Creates the surface.
	initSurface();
}

//Creates the SDL_Surface on which the text will be drawn
void Text::initSurface() {
	TTF_Init(); //Initializes the TTF class
	SDL_Color c = (getColor().getColor()); //The color of the text
	font = TTF_OpenFont("FreeSans.ttf", size); //Opens the font
	textSurface = TTF_RenderText_Solid(font, text.c_str(), c); //Renders the text to the surface.
}

//Returns a pointer to a deep copied copy of this text object.
Shape* Text::clone() const{
	return new Text(*this);
}

//Draws this text to the screen using the renderer
void Text::draw(Graphics& graphics) {
	SDL_Renderer& renderer = graphics.getRenderer();
	int mWidth = textSurface->w;  //The width of the text surface
	int mHeight = textSurface->h; //The height of the text surface
	mTexture = SDL_CreateTextureFromSurface(&renderer, textSurface); //Creates the texture containing the text
	SDL_Rect r = { x,y,x + mWidth/4,y + mHeight/4};
	SDL_RenderCopy(&renderer, mTexture, NULL, &r); //Renders the textures to the screen, inside rht rectangle r.
	SDL_DestroyTexture(mTexture); //Destroys teh texture
}
