#include "../include/MenuScene.h"

// Override method where handle control events in the scene
void MenuScene::HandleEvents(SDL_Event& event) {

	if (event.type == SDL_EVENT_KEY_DOWN) {						/* Here verify if use keyboard key down */  
		if (event.key.key == SDLK_RETURN) {						/* If the key is start,  initialize game*/
			std::cout << "Game Start\n";						/* Logic after the start key */
		}
	}
}

// Update method scene 
void MenuScene::Update() {

}

// Override control render in this scene 
void MenuScene::Render(SDL_Renderer* renderer) {

}

