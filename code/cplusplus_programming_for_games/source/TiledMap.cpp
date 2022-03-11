#include "TiledMap.h"


TiledMap::TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename, int screenHeight, int screenWidth)
{
	renderer = sdlRenderer;
	filename = tiledMapFilename;
	tileWidth = screenWidth/ 20;
	tileHeight = screenHeight/ 16;
}

int TiledMap::init()
{
	image = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	std::ifstream fileIn("assets/map.txt");
	if (fileIn.is_open())
	{
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				std::string tile;
				fileIn >> tile;
				map[i][j] = std::stoi(tile);
			}
		}
	}
	fileIn.close();
	
	return 0;
}

void TiledMap::render()
{
	//test++;
	//map[0][0] = test;
	//if (test > 100)
	//{
	//	test = 0;
	//}

	if (SDL_GetTicks() - lastChangeTile > changeTile)
	{
		tileMapChange = 90;
		map[2][4] = tileMapChange;
		lastChangeTile = SDL_GetTicks();
	}
	else if (SDL_GetTicks() - lastChangeTile > 1900)
	{
		tileMapChange = 88;
		map[1][10] = tileMapChange;
	}
	else if (SDL_GetTicks() - lastChangeTile > 1700)
	{
		tileMapChange = 94;
		map[6][17] = tileMapChange;
	}
	else if (SDL_GetTicks() - lastChangeTile > 1500)
	{
		tileMapChange = 94;
		map[13][5] = tileMapChange;
	}
	else if (SDL_GetTicks() - lastChangeTile > 1300)
	{
		tileMapChange = 96;
		map[1][10] = tileMapChange;
	}
	else
	{
		tileMapChange = 86;
		map[2][4] = tileMapChange;
		map[1][10] = tileMapChange;
		map[6][17] = 90;
		map[13][5] = tileMapChange;
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			SDL_Rect sourceRect;
			sourceRect.x = (map[i][j] % 20) * sourceTileSizePix;
			sourceRect.y = (map[i][j] / 20) * sourceTileSizePix;
			sourceRect.h = sourceTileSizePix;
			sourceRect.w = sourceTileSizePix;

			SDL_Rect renderRect;
			renderRect.x = j * tileWidth;
			renderRect.y = i * tileHeight;
			renderRect.h = tileHeight;
			renderRect.w = tileWidth;

			SDL_RenderCopy(renderer, texture, &sourceRect, &renderRect);
		}
	}
}

void TiledMap::clean()
{
	SDL_DestroyTexture(texture);
}