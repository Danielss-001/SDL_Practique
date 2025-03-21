#include <SDL3/SDL.h> 
#include "../include/GameWindow.h"
#include "../include/Player.h"
#include "../include/Levels.h"
#include "../include/Level.h"
#include "../include/Camera.h"
#include "../include/GameScene.h"
#include "../include/FactoryScene.h"
#include "../include/config.h"



int main() {
	
	GameWindow window(SCREEN_WIDTH,SCREEN_HEIGHT);						   // Create instance window
	Camera camera(0.0f,0.0f,SCREEN_WIDTH_CAMERA,SCREEN_HEIGHT_CAMERA);	   // Initialice coordenates camera in zero
	Player player(50.0f, 100.0f, PLAYER_WIDTH, PLAYER_HEIGHT);			   // Create instance Player
	Level level;														   // Call instance level

	

	FactoryScene factory_scene(player,level);							   // Factory class	

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////  This initialization, must be in a global file ///////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if(!window.init()) {												   // If not initialization window | Called the initialice window
		return -1;
	}
	
	
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	while (true) {
				
		window.HandleResize(camera);									   // Call resize camera with window

		SDL_Renderer* render = window.getRenderer();					   // Render variable || implement initialized in window
		
		//////////////////////////////////////////////////// CALLED THE FACTORY CLASS ////////////////////////////////////////////////////////////////
		
		// All implementations are in factory update.
		
			//game_scene.HandleEvents();
			//game_scene.Render(render,camera);
			//game_scene.Update(render,camera,LEVEL_WIDTH,LEVEL_HEIGHT);
		
		factory_scene.Update(window, render,camera,LEVEL_WIDTH,LEVEL_HEIGHT); // Control of scenes with factory pattern

		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		

		window.present();												   // Present and rendering window
		SDL_Delay(16);													   // Here method SDL for control change in loop, in milliseconds ()
	}
	return 0;
}

