#include "stdafx.h"
#include "Text.h"

#include <iostream>

using namespace std;

Text::Text(int x, int y, string text, Color color) :Shape(color) {
	init(x, y, text, 72);
}

Text::Text(int x, int y, string text, Color color, int size) : Shape(color) {
	init(x, y, text, size);
}

Text::Text(const Text& other) : Shape(other), x(other.x), y(other.y), text(other.text), size(other.size) {
	initSurface();
}

Text& Text::operator=(const Text& other) {
	if (&other == this) {
		return *this;
	}
	else {
		x = other.x;
		y = other.y;
		text = other.text;
		size = other.size;
		SDL_FreeSurface(textSurface);
		TTF_CloseFont(font);
		initSurface();
		return *this;
	}
}

Text::~Text() {
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}


std::string Text::toString() const{
	return "text";
}

void Text::init(int x, int y, string text, int size) {
	this->x = x;
	this->y = y;
	this->text = text;
	this->size = size;
	initSurface();
}

void Text::initSurface() {
	TTF_Init();
	SDL_Color c = (getColor().getColor());
	font = TTF_OpenFont("FreeSans.ttf", size);
	textSurface = TTF_RenderText_Solid(font, text.c_str(), c);
}

Shape* Text::clone() const{
	return new Text(*this);
}

void Text::draw(SDL_Renderer &renderer) {
	int mWidth = textSurface->w;
	int mHeight = textSurface->h;
	mTexture = SDL_CreateTextureFromSurface(&renderer, textSurface);
	SDL_Rect r = { x,y,x + mWidth/4,y + mHeight/4};
	SDL_RenderCopy(&renderer, mTexture, NULL, &r);
	SDL_DestroyTexture(mTexture);
}
