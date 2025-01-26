#include "../include/Player.h"

// Here constructor player
Player::Player(float x, float y, float width, float height) : rect({x,y,width,height}), velocityX(0.0f), velocityY(0.0f), isJumping(false) {}

void Player::HandleInput() {

	SDL_Event e;														  // Implement SDLEvent for capturing anything event

	while (SDL_PollEvent(&e) != 0 ) {									  // Its true if capturing anything event
		if (e.type == SDL_EVENT_QUIT) {									  // If event-type is quit application
			SDL_Quit();													  // Stop SDL game
			exit(0);													  // Close window
		}

		if (e.type == SDL_EVENT_KEY_DOWN) {                               // If pressed key in keyboard
			if (e.key.key == SDLK_LEFT) {								  // Pressed left key
				velocityX = -5;											  // Motion at left | less velocity in X axis
			}
			if (e.key.key == SDLK_RIGHT) {								  // Pressed right key
				velocityX = 5;											  // Motion at right | addition velocity in X axis
			}
			if (e.key.key == SDLK_SPACE && !isJumping ) {				  // Pressed space key and isjumping is false
				velocityY = -15;										  // Motion at up | less velocity in Y axis
				isJumping = true;										  // Variable isJumping now is true
			}
		}

		if (e.type == SDL_EVENT_KEY_UP) {								  // If release key in keyword
			if (e.key.key == SDLK_LEFT || e.key.key == SDLK_RIGHT) {	  // If release left and right...
				velocityX = 0;											  // Determinate velocity in zero | Stop motion
			}
		}
		
	}
}

void Player::Update(const std::vector<SDL_FRect> solidTiles) {			  // Method update player

	// Vertical move
	rect.y += velocityY;
	for (const auto& tile : solidTiles) {

		// Tile Dimensions
		float tileLeft = tile.x;
		float tileRight = tile.x + tile.w;
		float tileTop = tile.y;
		float tileBottom = tile.y + tile.h;

		// Player Dimensions
		float playerLeft = rect.x;
		float playerRight = rect.x + rect.w;
		float playerTop = rect.y;
		float playerBottom = rect.y + rect.h;

		// Detecting vertical collision
		if (playerRight > tileLeft && playerLeft < tileRight && playerTop < tileBottom && playerBottom > tileTop) {
			
			if (velocityY > 0) {										// Move player down
				rect.y = tileTop - rect.h;								// put player upon tile 
				velocityY = 0;											// Velocity in zero | Stop motion
				isJumping = false;										// Available for jumping
			}
			else if (velocityY < 0) {									// Move player up
				rect.y = tileBottom;									// Put player blelow tile
				velocityY = 0;											// Velocity in zero | Stop motion
			}
		}
		
	}

	// Horizontal move
	rect.x += velocityX;
	for (const auto& tile : solidTiles) {
		
		// Tile Dimensions
		float tileLeft = tile.x;
		float tileRight = tile.x + tile.w;
		float tileTop = tile.y;
		float tileBottom = tile.y + tile.h;

		// Player Dimensions
		float playerLeft = rect.x;
		float playerRight = rect.x + rect.w;
		float playerTop = rect.y;
		float playerBottom = rect.y + rect.h;

		// Detecting vertical collision
		if (playerRight > tileLeft && playerLeft < tileRight && playerTop < tileBottom && playerBottom > tileTop) {

			if (velocityX > 0) {										// Move player right
				rect.x = tileLeft - rect.w;								// put player upon tile 
				velocityX = 0;											// Velocity in zero | Stop motion
			}
			else if (velocityX < 0) {									// Move player left
				rect.x = tileRight;										// Put player blelow tile
				velocityX = 0;											// Velocity in zero | Stop motion
			}
		}
	}

	if (rect.y < 2000) {													// If position player down 
		velocityY += 1;													// Applicate gravity in velocity in Y axis 
	}
	else{																// Otherwise if player is grounded
		velocityY = 0;													// Velocity determinate in zero
		isJumping = false;												// Is jumping determinate in false 
	}
	
}

void Player::Render(SDL_Renderer* renderer ) {							// Render player
	SDL_SetRenderDrawColor(renderer,255,0,0,255);						// First complement color renderer 
	SDL_RenderFillRect(renderer,&rect);									// Second used FillRect for add render and FRect | Show rect in window
}

const SDL_FRect& Player::getRect(SDL_Renderer* renderer) const {										// Getting rect player
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);						// First complement color renderer 
	return rect;
}