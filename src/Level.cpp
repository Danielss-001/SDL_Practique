#include "../include/Level.h"


void Level::RenderLevel(std::vector<std::vector<int>> level, SDL_Renderer* renderer) {									// ***IMPORTANT***The render function must camera view
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	levelMap = level;											    // copy matriz 2D in the variable for change levels
	SDL_SetRenderDrawColor(renderer,1,75,0,0);                      // Change color the render tile, using renderer and color in RGB
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (size_t i = 0; i < levelMap.size();i++) {					// Runs through the matriz -->*...
		for (size_t j = 0; j < levelMap[i].size();j++) {			// ...*<-- Runs through the matriz

			if (levelMap[i][j] == 1) {								// If the matriz an tile equal one | renderice
				SDL_FRect rectlevel = {
					i*TILE_SIZE,
					j*TILE_SIZE,
					TILE_SIZE,
					TILE_SIZE};
				SDL_RenderFillRect(renderer,&rectlevel);		    // Construct rect using | render and SDL_FRect 
			}
		}
	}
}

// Colisioner coordenates for use with player update detected collisions | Manager collisions in player update
std::vector<SDL_FRect> Level::IsSolidCollisioner(std::vector<std::vector<int>> level, SDL_Renderer* renderer)  {	   // Determinate collisioner box | return vector the all solid tiles coordenates
	
	levelMap = level;											    // copy matriz 2D in the variable for change levels

	SDL_SetRenderDrawColor(renderer, 1, 75, 0, 0);                      // Change color the render tile, using renderer and color in RGB

	std::vector<SDL_FRect> solidTiles;

	for (size_t y = 0; y < levelMap.size(); y++) {
		for (size_t x = 0; x < levelMap[y].size(); x++) {

			if (levelMap[y][x] == 1) {							    // Here Solid Block, getting coordenates
				SDL_FRect tileRect = {								// Implement SDL_FRect for coordenate for each tile
					y * TILE_SIZE,									// Multiply position in x and tile size
					x * TILE_SIZE,									// Multiply position in y and tile size
					TILE_SIZE,										
					TILE_SIZE
				};
				solidTiles.push_back(tileRect);					    // Add solid tiles in vector | Coordenates
			}
		}
	}
	return solidTiles;												// Return vector all tiles solid in coordenates 
}

float Level::GetTitleSize() const {
	return TILE_SIZE;
}