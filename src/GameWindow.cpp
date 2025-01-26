#include "../include/GameWindow.h"

GameWindow::GameWindow(int width, int height) : window(nullptr), renderer(nullptr), width(width), height(height) {}

GameWindow::~GameWindow() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool GameWindow::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 1) {
		std::cerr << "El error es: "<< SDL_GetError()<<std::endl;
		return false;
	}
	
	window = SDL_CreateWindow("Mini Mario Bros", width, height, SDL_WINDOW_RESIZABLE); // Created window

	if (!window) {
		std::cerr << "Error en la ventana: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window,NULL); // Created render for all application

	if (!renderer) {
		std::cerr << "Error al crear el renderizado: " << SDL_GetError()<<std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	return true;
}

void GameWindow::clear() {
	SDL_SetRenderDrawColor(renderer, 66, 199, 255, 0);		// Here applicate color render, in this case to window
	SDL_RenderClear(renderer);								// Clear window and restart rendering
}

void GameWindow::present() {
	SDL_RenderPresent(renderer);
}

 SDL_Renderer* GameWindow::getRenderer() const {
	return renderer;
}