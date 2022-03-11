#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class ImageRenderer
{
public:
	ImageRenderer(const char* picture, SDL_Renderer* render, int width, int height, int x, int y);
	~ImageRenderer() { destroy(); };
	void render();
	void destroy();

private:
	SDL_Texture* texture;
	SDL_Rect portion;
	SDL_Surface* image;
	SDL_Renderer* renderer;
	int posX, posY, scaleX, scaleY;
};

