#pragma once
#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL_image.h>
#include <SDL.h>

#include "FontRenderer.h"
#include "TiledMap.h"
#include "ImageRenderer.h"

const int screenWidth = 1200;
const int screenHeight = 720;

class GameLoop
{

public:
	int init();
	void update();
	void render();
	void clean();
	void color(int red, int green, int blue);

	bool keepAlive();

	SDL_Renderer* getRenderer() { return renderer; }
	SDL_Surface* getSurface() { return screenSurface; }

	int score;

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	ImageRenderer* IR1;
	ImageRenderer* IR2;
	ImageRenderer* IR3;
	ImageRenderer* IR4;
	ImageRenderer* IR5;

	ImageRenderer* IR6;
	ImageRenderer* IR7;
	ImageRenderer* IR8;
	ImageRenderer* IR9;

	std::unique_ptr<FontRenderer> fontRenderer;
	TiledMap* tiledMap;
};