#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "../include/Player.h"

#define TILE_SIZE 45.0f


class Level {
private:
	std::vector<std::vector<int>> levelMap;
public:

	void RenderLevel(std::vector<std::vector<int>> level, SDL_Renderer*);
	std::vector<SDL_FRect> IsSolidCollisioner(std::vector<std::vector<int>> level, SDL_Renderer* renderer) ;
	float GetTitleSize()const;
};
