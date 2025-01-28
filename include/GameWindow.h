#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "../include/Camera.h"

class GameWindow {
private:
	/* **< Variables initializing window. add SDL_Window SDL_Renderer and width height in int types */
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width, height;

public:

	// Initialice constructor window the game. using variables privates
	GameWindow(int width, int height);
	// Destructor where all variables | window | renderer
	~GameWindow();

	// Here init the window and renderer 
	bool init();				
	bool HandleResize(Camera& camera);
	void clear();
	void present();

	SDL_Renderer* getRenderer() const;
};
