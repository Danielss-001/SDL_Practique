#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <vector>

class Player {
private:
	SDL_FRect rect;
	float velocityX, velocityY;
	bool isJumping;

public:
	// Initiliced constructor
	Player(float x, float y, float width, float height);
	void HandleInput();
	void Update(const std::vector<SDL_FRect>);
	void Render(SDL_Renderer* renderer);

	const SDL_FRect& getRect(SDL_Renderer* renderer) const;
};
