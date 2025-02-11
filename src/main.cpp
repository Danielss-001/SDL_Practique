#include <SDL3/SDL.h> 
#include <SDL3_ttf/SDL_ttf.h>											   // Text dependencies
#include "../include/GameWindow.h"
#include "../include/Player.h"
#include "../include/Levels.h"
#include "../include/Level.h"
#include "../include/Camera.h"
#include "../include/GameScene.h"

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 500
#define PLAYER_WIDTH 20.0f
#define PLAYER_HEIGHT 20.0f
#define SCREEN_WIDTH_CAMERA 700
#define SCREEN_HEIGHT_CAMERA 500 

#define LEVEL_WIDTH 50 * 45												   //The width Used the multiply N° rows in total || Is use for render camera
#define LEVEL_HEIGHT 16 * 45											   //The height Used the multiply N° columns in total || Is use for render camera

int main() {
	
	GameWindow window(SCREEN_WIDTH,SCREEN_HEIGHT);						   // Create instance window
	Camera camera(0.0f,0.0f,SCREEN_WIDTH_CAMERA,SCREEN_HEIGHT_CAMERA);	   // Initialice coordenates camera in zero
	Player player(50.0f, 100.0f, PLAYER_WIDTH, PLAYER_HEIGHT);			   // Create instance Player
	Level level;														   // Call instance level

	GameScene game_scene(player,level,Levels::levelOne);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////  This initialization, must be in a global file ///////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if(!window.init()) {												   // If not initialization window 
		return -1;
	}
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (true) {
				
		window.HandleResize(camera);									   // Call resize camera with window

		window.clear();													   // Clear window rewrite color and render


		SDL_Renderer* render = window.getRenderer();						   // Render variable || implement initialized in window
		
		///////////////////////////////////// TEST SCENE /////////////////////////////////////////////////////////////////////////////////////////////
		
		game_scene.HandleEvents();
		game_scene.Render(render,camera);
		game_scene.Update(render,camera,LEVEL_WIDTH,LEVEL_HEIGHT);

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		

		window.present();												  
		SDL_Delay(16);													   // Here method SDL for control change in loop, in milliseconds ()
	}
	return 0;
}

