#include "../include/GameWindow.h"

GameWindow::GameWindow(int width, int height) :										// In this constructor, it sets to 0 each of the variables of the structe Color
	window(nullptr), 
	renderer(nullptr), 
	width(width), 
	height(height) {

	background_color.r = 0;						
	background_color.g = 0;
	background_color.b = 0;
	background_color.a = 0;
}

GameWindow::~GameWindow() {															// Delete everything: The render and the window. and don't forget to exit the game.
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool GameWindow::init() {															// Init the window and render
	if (SDL_Init(SDL_INIT_VIDEO) != 1) {
		std::cerr << "El error es: "<< SDL_GetError()<<std::endl;
		return false;
	}
	
	window = SDL_CreateWindow("Mini Mario Bros", width, height, SDL_WINDOW_RESIZABLE);// Created window

	if (!window) {
		std::cerr << "Error en la ventana: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	renderer = SDL_CreateRenderer(window,NULL);										// Created render for all application

	if (!renderer) {																// If fail renderer
		std::cerr << "Error al crear el renderizado: " << SDL_GetError()<<std::endl;// Comment take error SDL type
		SDL_DestroyWindow(window);													// Destroy window
		SDL_Quit();																	// Finish program
		return false;
	}
	return true;
}

void GameWindow::SetBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {			// Sets the background color with new values | using the Uint8 equal to 8 bits
	background_color.r = r;
	background_color.g = g;
	background_color.b = b;
	background_color.a = a;

	SDL_SetRenderDrawColor(renderer,r,g,b,a);										// Here applicate color render, in this case to window

}

Color GameWindow::GetBackgroundColor() {											// This method get background color in: r, g, b, a							

	return background_color;														// Return struct with color changes
}

bool GameWindow::HandleResize(Camera& camera) {										// Here method control resize window, and resize control camera
	
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
	
	SDL_RenderClear(renderer);														// Clear window and restart rendering
}

void GameWindow::present() {														// Draw any object to be rendered using the renderer and rendering settings
	SDL_RenderPresent(renderer);
}

 SDL_Renderer* GameWindow::getRenderer() const {									// Get renderer
	return renderer;
}