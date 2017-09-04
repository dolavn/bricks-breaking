#pragma once

#include "Shape.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text :public Shape {
public:
	Text(int x, int y, std::string text, Color color);
	Text(int x, int y, std::string text, Color color, int size);
	Text(const Text& other);
	Text& operator=(const Text& other);
	virtual ~Text();
	virtual void draw(SDL_Renderer &renderer);
	virtual Shape* clone() const;
	virtual std::string toString() const;
private:
	int x;
	int y;
	int size;
	SDL_Surface *textSurface = NULL;
	SDL_Texture *mTexture = NULL;
	TTF_Font *font = NULL;
	std::string text;
	void init(int x, int y, std::string text, int size);
	void initSurface();
};