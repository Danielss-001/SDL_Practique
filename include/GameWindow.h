#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include "../include/Camera.h"

struct Color {
	Uint8 r, g, b, a;
};

class GameWindow {
private:
	/* **< Variables initializing window. add SDL_Window SDL_Renderer and width height in int types */
	SDL_Window* window;
	SDL_Renderer* renderer;
	int width;
	int height;
	Color background_color;
public:

	// Initialice constructor window the game. using variables privates
	GameWindow(int width, int height);
	// Destructor where all variables | window | renderer
	~GameWindow();

	// Here init the window and renderer 
	bool init();			

	// This method sets the background color to be used in the factory class >>
	// It changes the background color depending on the level
	void SetBackgroundColor(Uint8, Uint8, Uint8, Uint8);

	// Obtein background color, color separated in r, g, b, a
	Color GetBackgroundColor();

	// This method resizes window and the camera
	bool HandleResize(Camera& camera);

	// Clear renderer
	void clear();

	// Present render
	void present();

	SDL_Renderer* getRenderer() const;
};
