#pragma once
#include <SDL3/SDL.h>
#include <vector>
#include "../include/Player.h"

#define TILE_SIZE 45.0f		// Sise tile preprocesor

// Color structure
struct TColor {											
	Uint8 r, g, b, a;
};

class Level {
private:
	std::vector<std::vector<int>> levelMap;
	TColor tile_color;
public:
	
	// LEVEL BOX COORDINATES | Method handle control coordenate level change rect 
	SDL_FRect ChangeLevelCoordenates(std::vector<std::vector<int>> level, SDL_Renderer* renderer);
	
	// This method used to render each tile in the level | However, this method is implemented and controlled by the camera class
	void RenderLevel(std::vector<std::vector<int>> level, SDL_Renderer*);
	
	// COLLIDER COORDINATES | for use with player update detected collisions | Manager collisions in player update
	std::vector<SDL_FRect> IsSolidCollisioner(std::vector<std::vector<int>> level, SDL_Renderer* renderer) ;

	// This method used to change new color values
	void SetTileColor(Uint8, Uint8, Uint8, Uint8);
	
	float GetTileSize()const;
};
