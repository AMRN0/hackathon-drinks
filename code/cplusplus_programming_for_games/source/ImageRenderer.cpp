#include "ImageRenderer.h"

ImageRenderer::ImageRenderer(const char* picture, SDL_Renderer* render, int width, int height, int x, int y)
{
	renderer = render;

	image = IMG_Load(picture);
	if (image == nullptr)
	{
		std::cout << "could not load picture!" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(this->renderer, image);
	SDL_FreeSurface(image);

	portion.w = width;
	portion.h = height;
	portion.x = x;
	portion.y = y;
}

void ImageRenderer::render()
{
	SDL_RenderCopy(renderer, texture, NULL, &portion);
}

void ImageRenderer::destroy()
{
	SDL_DestroyTexture(texture);
}
