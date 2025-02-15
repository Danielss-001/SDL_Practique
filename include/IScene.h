#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include "../include/Player.h"
#include "../include/Level.h"
#include "../include/Camera.h"
#include <vector>


class IScene {
public:
	virtual void HandleEvents() = 0;											// Handle control events inside events
	virtual void Update(SDL_Renderer* renderer,Camera&,int,int) = 0;			// Handle inputs and update scene
	virtual void Render(SDL_Renderer* renderer, Camera&) = 0;					// Handle control renderer each scene

	virtual ~IScene() = default;												// Destructor scene
};