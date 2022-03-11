#pragma once
#include <SDL_ttf.h>
#include <SDL.h>
#include <string>
#include <iostream>
#include <SDL_image.h>

class FontRenderer
{
public:
	FontRenderer(SDL_Renderer* sdlRenderer);

	void init();
	void render(std::string text, int posX, int posY, int type, int sizeX, int sizeY);
	void clean();

private:
	int windowWidth = 1200, windowHeight = 720, posX, posY;
	float textWidth, textHeight;

	SDL_Renderer* renderer;
	TTF_Font* font;
	SDL_Rect score;
	SDL_Surface* textImage;
};