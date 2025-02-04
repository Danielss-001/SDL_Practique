#include "../include/Level.h"


void Level::RenderLevel(std::vector<std::vector<int>> level, SDL_Renderer* renderer) {									// ***IMPORTANT***The render function must camera view
	// Method no necessary: Because delegates control to camera
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

// Method handle control coordenate level change rect
SDL_FRect Level::ChangeLevelCoordenates(std::vector<std::vector<int>> level, SDL_Renderer* renderer) {
	
	SDL_FRect ChangeLevel = {0.0f,0.0f,0.0f,0.0f};					// Call variable type SDL_FRect, for implement coordenates in chanche level box
	levelMap = level;												// Call variable copy level matriz for using loop and iterate 

	SDL_SetRenderDrawColor(renderer, 0,113,255,0);					// Set color SDL_FRect for the box change level

	for (size_t x = 0; x < levelMap.size(); x++) {					// Run through the matriz level map
		for (size_t y = 0; y < levelMap[x].size(); y++) {

			if (levelMap[x][y] == 2) {								// verify if the value in level is equal 2
				ChangeLevel = {										// Update variable with the news coordenates 
					x * TILE_SIZE,									// Multiply x axis and tile size
					y * TILE_SIZE,									// Multiply y axis and tile size
					TILE_SIZE,
					TILE_SIZE
				};
			}
		}
	}
	return ChangeLevel;												// Return SDL_FRect, where implement new coorenate and set color in render

}

// Colisioner coordenates for use with player update detected collisions | Manager collisions in player update
std::vector<SDL_FRect> Level::IsSolidCollisioner(std::vector<std::vector<int>> level, SDL_Renderer* renderer)  { // Determinate collisioner box | return vector the all solid tiles coordenates
	
	levelMap = level;											    // copy 2D matriz in the variable for change levels

	SDL_SetRenderDrawColor(renderer, 1, 75, 0, 0);                  // Change color the render tile, using renderer and color in RGB

	std::vector<SDL_FRect> solidTiles;

	for (size_t x = 0; x < levelMap.size(); x++) {
		for (size_t y = 0; y < levelMap[x].size(); y++) {

			if (levelMap[x][y] == 1) {							    // Here Solid Block, getting coordenates
				SDL_FRect tileRect = {								// Implement SDL_FRect for coordenate for each tile
					x * TILE_SIZE,									// Multiply position in x and tile size
					y * TILE_SIZE,									// Multiply position in y and tile size
					TILE_SIZE,										
					TILE_SIZE
				};
				solidTiles.push_back(tileRect);					    // Add solid tiles in vector | Coordenates
			}
		}
	}
	return solidTiles;												// Return vector all tiles solid in coordenates 
}

float Level::GetTileSize() const {
	return TILE_SIZE;
}