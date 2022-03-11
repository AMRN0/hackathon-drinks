#include "FontRenderer.h"


FontRenderer::FontRenderer(SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;
}

void FontRenderer::init()
{
	int init = TTF_Init();
	if (init != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	font = TTF_OpenFont("assets/NeoTech.ttf", 100);

	if (font == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
	}

	score.x = 25;
	score.y = 10;
}

void FontRenderer::render(std::string text, int posX, int posY, int type, int sizeX, int sizeY)
{
	SDL_Color colour = SDL_Color();
	colour.r = 255;
	colour.g = 255;
	colour.b = 255;
	colour.a = 255;

	SDL_Color bgcolour = SDL_Color();
	bgcolour.r = 0;
	bgcolour.g = 0;
	bgcolour.b = 0;
	bgcolour.a = 255;

	if (type == 0)
	{
		textImage = TTF_RenderText_Solid(font, text.c_str(), colour);
	}

	else if (type == 1)
	{
		textImage = TTF_RenderText_Shaded(font, text.c_str(), colour, bgcolour);
	}

	

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textImage);

	score.x = posX;
	score.y = posY;
	
	score.w = sizeX;
	score.h = sizeY;
	SDL_RenderCopy(renderer, texture, NULL, &score);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textImage);
}

void FontRenderer::clean()
{
	TTF_CloseFont(font);
}