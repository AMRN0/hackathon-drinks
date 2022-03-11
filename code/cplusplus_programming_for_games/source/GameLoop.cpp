#include "GameLoop.h"


int GameLoop::init()
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "could not initialise SDL2!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}

	window = SDL_CreateWindow(
		"Hackathon",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		std::cout << "could not initialise window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	screenSurface = SDL_GetWindowSurface(window);

	SDL_UpdateWindowSurface(window);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "could not initialise renderer!" << std::endl;
		std::cout << SDL_GetError << std::endl;
	}



	tiledMap = new TiledMap(renderer, "assets/tilemap-separated.png", screenHeight, screenWidth);
	tiledMap->init();

	fontRenderer = std::unique_ptr<FontRenderer>(new FontRenderer(renderer));
	fontRenderer->init();

	IR1 = new ImageRenderer("assets/cola.png", renderer, 100, 50, 50, 100);
	IR2 = new ImageRenderer("assets/diet cola.png", renderer, 100, 50, 50, 200);
	IR3 = new ImageRenderer("assets/lemonade.png", renderer, 100, 50, 50, 300);
	IR4 = new ImageRenderer("assets/Dandelion and Burdock.png", renderer, 100, 50, 50, 400);
	IR5 = new ImageRenderer("assets/orange.png", renderer, 100, 50, 50, 500);
	IR6 = new ImageRenderer("assets/teacakes.png", renderer, 100, 50, 700, 100);
	IR7 = new ImageRenderer("assets/lolipops.png", renderer, 100, 50, 700, 200);
	IR8 = new ImageRenderer("assets/parma.png", renderer, 100, 50, 700, 300);
	IR9 = new ImageRenderer("assets/chocolate.png", renderer, 100, 50, 700, 400);

	return 0;
}

void GameLoop::update()
{

}

void GameLoop::render()
{
	SDL_RenderClear(renderer);

	color(99, 155, 255);

	tiledMap->render();

	//titles
	fontRenderer->render("Drinks at a hackathon: ", 10, 10, 1, 500, 50);
	fontRenderer->render("Sweets at a hackathon: ", screenWidth / 5 * 3 - 50, 10, 1, 500, 50);

	//numbers
	fontRenderer->render("24 Litres", 200, 100, 0, 250, 50);
	fontRenderer->render("20 Litres", 200, 200, 0, 250, 50);
	fontRenderer->render("19 Litres", 200, 300, 0, 250, 50);
	fontRenderer->render("60 Litres", 200, 400, 0, 250, 50);
	fontRenderer->render("10 Litres", 200, 500, 0, 250, 50);

	fontRenderer->render("600g", 850, 100, 0, 250, 50);
	fontRenderer->render("700g", 850, 200, 0, 250, 50);
	fontRenderer->render("300g", 850, 300, 0, 250, 50);
	fontRenderer->render("500g", 850, 400, 0, 250, 50);

	IR1->render();
	IR2->render();
	IR3->render();
	IR4->render();
	IR5->render();
	IR6->render();
	IR7->render();
	IR8->render();
	IR9->render();

	SDL_RenderPresent(renderer);
}

bool GameLoop::keepAlive()
{
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput) != 0) {
		if (userInput.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}

void GameLoop::clean()
{
	fontRenderer->clean();
	tiledMap->clean();
	delete IR1, IR2, IR3, IR4, IR5, IR6, IR7, IR8, IR9;
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void GameLoop::color(int red, int green, int blue)
{
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, red, green, blue));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, screenSurface);
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	SDL_DestroyTexture(texture);
}