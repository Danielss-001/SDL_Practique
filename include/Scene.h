#pragma once
#include <iostream>
#include <SDL3/SDL.h>
#include "../include/Player.h"
#include "../include/Level.h"

class Scene {
public:
	virtual void HandleEvents(SDL_Event& event) = 0;		// Handle control events inside events
	virtual void Update() = 0;								// Handle inputs and update scene
	virtual void Render(SDL_Renderer* renderer) = 0;		// Handle control renderer each scene

	virtual ~Scene() = default;								// Destructor scene
};