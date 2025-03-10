#include "../include/Player.h"

// Here constructor player
Player::Player(float x, float y, float width, float height) : rect({x,y,width,height}), velocityX(0.0f), velocityY(0.0f), isJumping(false) {}

void Player::HandleInput(const SDL_Event& event) {					      // We leave the control of the main event loop in the game scene settings

	if (event.type == SDL_EVENT_KEY_DOWN) {                               // If pressed key in keyboard
		if (event.key.key == SDLK_LEFT) {								  // Pressed left key
			velocityX = -5;												  // Motion at left | less velocity in X axis
		}
		if (event.key.key == SDLK_RIGHT) {								  // Pressed right key
			velocityX = 5;											      // Motion at right | addition velocity in X axis
		}
		if (event.key.key == SDLK_SPACE && !isJumping) {				  // Pressed space key and isjumping is false
			velocityY = -15;										      // Motion at up | less velocity in Y axis
			isJumping = true;										      // Variable isJumping now is true
		}
	}

	if (event.type == SDL_EVENT_KEY_UP) {								  // If release key in keyword
		if (event.key.key == SDLK_LEFT || event.key.key == SDLK_RIGHT) {  // If release left and right...
			velocityX = 0;											      // Determinate velocity in zero | Stop motion
		}
	}
}

 

void Player::Update(const std::vector<SDL_FRect> solidTiles, const SDL_FRect levelBox){ 
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

		// Detecting horizontal collision
		if (playerRight > tileLeft && playerLeft < tileRight && playerTop < tileBottom && playerBottom > tileTop) {

			if (velocityX > 0) {										// Move player right
				rect.x = tileLeft - rect.w;								// put player upon tile 
				velocityX = 0;											// Velocity in zero | Stop motion
			}
			else if (velocityX < 0) {									// Move player left
				rect.x = tileRight;										// Put player bellow tile
				velocityX = 0;											// Velocity in zero | Stop motion
			}
		}
	}

	ChangeLevelCheck(levelBox);											// Detect level change box and throw events in contact with these box 

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (rect.y < 2000) {												// If position player down 
		velocityY += 1;													// Applicate gravity in velocity in Y axis 
	}
	else{																// Otherwise if player is grounded
		velocityY = 0;													// Velocity determinate in zero
		isJumping = false;												// Is jumping determinate in false 
	}
	


}
bool Player::ChangeLevelCheck(const SDL_FRect levelBox) {				// This method checks for collisions between the level box and the player
	
	// Level box dimensions
	float boxLeft = levelBox.x;
	float boxRight = levelBox.x + levelBox.w;
	float boxTop = levelBox.y;
	float boxBottom = levelBox.y + levelBox.h;

	// Player dimensions
	float playerLeft = rect.x;
	float playerRight = rect.x + rect.w;
	float playerTop = rect.y;
	float playerBottom = rect.y + rect.h;

	// Detecting collision with change level box // level change 
	if (playerRight > boxLeft && 
		playerLeft < boxRight && 
		playerTop < boxBottom && 
		playerBottom > boxTop) {

		return true;
	}

	return false;
}

bool Player::PlayerIsDead() {											// This method checks if the player dead
	if (rect.y > 700) {													// If the player has fallen down 
		return true;
	}
	return false;														// Return bool for use in Update game scene method
}

void Player::Render(SDL_Renderer* renderer ) {							// Render player
	SDL_SetRenderDrawColor(renderer,255,0,0,255);						// First complement color renderer 
	SDL_RenderFillRect(renderer,&rect);									// Second used FillRect for add render and FRect | Show rect in window
}

const SDL_FRect& Player::getRect(SDL_Renderer* renderer) const {		// Getting rect player
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);					// First complement color renderer 
	return rect;
}