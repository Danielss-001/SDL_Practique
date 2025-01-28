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

	renderer = SDL_CreateRenderer(window,NULL);										  // Created render for all application

	if (!renderer) {
		std::cerr << "Error al crear el renderizado: " << SDL_GetError()<<std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return false;
	}
	return true;
}

bool GameWindow::HandleResize(Camera& camera) {										 // Here method control resize window, and resize control camera
	
	SDL_Event event;																// First. capturin event
	bool resized = false;															// init the variable bool in false

	while (SDL_PollEvent(&event)) {													// Second. lisening all event in game
		if (event.window.type == SDL_EVENT_WINDOW_RESIZED) {						// Three. If the event is resize window 
			
			int newWidth = event.window.data1;										// Four. Take new width resize window in variable newWidth...
			int newHeight = event.window.data2;										// ... Take new height resize window in variable newHeight

			camera.CameraResize(newWidth,newHeight);								// Five. Call camera method for resize camera and pass new data 

			width = newWidth;														// Six. Change the variables globals the window game...
			height = newHeight;														// ... New data in window variables

			resized = true;															// Change assignment the variable 'resized' in true
		}
		else {
			SDL_PushEvent(&event);													// Seven. ..IMPORTANT.. We return to put in quee all events not lisening
		}
	}
	return resized;																	// Return variable 'resized'
	
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