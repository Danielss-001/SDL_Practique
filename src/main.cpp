#include <SDL3/SDL.h> 
#include "../include/GameWindow.h"
#include "../include/Player.h"
#include "../include/Levels.h"
#include "../include/Level.h"

#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 500
#define PLAYER_WIDTH 20.0f
#define PLAYER_HEIGHT 20.0f

int main() {
	
	GameWindow window(SCREEN_WIDTH,SCREEN_HEIGHT);
	Player player(50.0f, 100.0f, PLAYER_WIDTH, PLAYER_HEIGHT);
	Level level;

	/*bool running = true;
	SDL_Event event;*/

	if(!window.init()) {
		return -1;
	}

	while (true) {
		
		//while (SDL_PollEvent(&event)) {
		//	if (event.type == SDL_EVENT_QUIT) {
		//		running = false;
		//		exit(0);
		//	}

		//	if (event.type == SDL_EVENT_KEY_DOWN) {
		//		/*std::cout << "Tecla presionada es: "<<SDL_GetScancodeName(event.key.scancode);*/
		//		if (event.key.key == SDLK_SPACE) {
		//			std::cout << "UP KEY" << std::endl;
		//		}
		//	}
		//}

		
		window.clear();

		level.RenderLevel(Levels::levelOne,window.getRenderer());
		
		std::vector<SDL_FRect> soliTiles = level.IsSolidCollisioner();

		player.HandleInput();
		player.Update(soliTiles);
		player.Render(window.getRenderer());
		

		window.present();
		SDL_Delay(16);
	}
	return 0;
}

