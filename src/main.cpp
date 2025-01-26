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
				
		window.clear();													   // Clear window rewrite color and render

		SDL_Renderer* render = window.getRenderer();					   // Render variable 

		camera.UpdateCamera(&player.getRect(render), LEVEL_WIDTH, LEVEL_HEIGHT);

		/*level.RenderLevel(Levels::levelOne,render);*/
		
		std::vector<SDL_FRect> soliTiles = level.IsSolidCollisioner(Levels::levelOne,render);	  // Calculate collisions tiles

		for (const auto& tile : soliTiles) {
			camera.RenderObject(window.getRenderer(),tile);
		}

		camera.RenderObject(render,player.getRect(render));

		player.HandleInput();
		player.Update(soliTiles);										  // In the update player implement collisions with world
		/*player.Render(window.getRenderer()); */
		

		window.present();
		SDL_Delay(16);
	}
	return 0;
}

