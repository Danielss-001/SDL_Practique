#include <SDL3/SDL.h> 
#include "../include/GameWindow.h"
#include "../include/Player.h"
#include "../include/Levels.h"
#include "../include/Level.h"
#include "../include/Camera.h"

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 500
#define PLAYER_WIDTH 20.0f
#define PLAYER_HEIGHT 20.0f
#define SCREEN_WIDTH_CAMERA 700
#define SCREEN_HEIGHT_CAMERA 500 

#define LEVEL_WIDTH 50 * 45													//The width Used the multiply N° rows in total || Is use for render camera
#define LEVEL_HEIGHT 16 * 45												//The height Used the multiply N° columns in total || Is use for render camera

int main() {
	
	GameWindow window(SCREEN_WIDTH,SCREEN_HEIGHT);
	Camera camera(0.0f,0.0f,SCREEN_WIDTH_CAMERA,SCREEN_HEIGHT_CAMERA);		// Initialice coordenates camera in zero
	Player player(50.0f, 100.0f, PLAYER_WIDTH, PLAYER_HEIGHT);
	Level level;


	if(!window.init()) {												   // If not initialiced window 
		return -1;
	}

	while (true) {
				
		window.HandleResize(camera);									   // Call resize camera with window

		window.clear();													   // Clear window rewrite color and render

		SDL_Renderer* render = window.getRenderer();					   // Render variable || implement initialized in window

		camera.UpdateCamera(&player.getRect(render), LEVEL_WIDTH, LEVEL_HEIGHT);

		
		std::vector<SDL_FRect> soliTiles = level.IsSolidCollisioner(Levels::levelOne,render);	  // Calculate collisions tiles

		for (const auto& tile : soliTiles) {							   // Here run through coordenates tiles vector 
			camera.RenderObject(window.getRenderer(),tile);				   // Use camera render object method for render each tile in vector / only equal to one or solid tile
		}

		camera.RenderObject(render,player.getRect(render));				  // Use render camera object method for render player
		

		player.HandleInput();											  // Call method control handle input player (events)
		player.Update(soliTiles);										  // In the update player implement collisions with world
		

		window.present();												  
		SDL_Delay(16);													  // Here method SDL for control change in loop, in milliseconds ()
	}
	return 0;
}

