#pragma once
#include "../include/IScene.h"
#include "../include/Player.h"
#include "../include/Levels.h"
#include "../include/GameWindow.h"
#include <memory>

class GameScene;							    // Forward declaration: GameScene statement for statements in this code | The "GameScene.h" in "FactoryScene.cpp"
class StartScene;								// Forward declaration: StartScene statement for statements in this code | The "StartScene.h" in "FactoryScene.cpp"
											    
class FactoryScene {						    
											    
private:									    
	Player					   player;		    
	Level					   level;
	std::unique_ptr<IScene>    game_scene;	    // Use of unique_ptr to control GameScene type instances
	int						   level_number;    // With numerical level for switching between levels	

public:
	// Constructor factory in main
	FactoryScene(Player& player, Level& level);

	// This method is used in the main loop of the game : Level chage
	void Update(GameWindow& window, SDL_Renderer* render, Camera&,int,int);

	// Method for setting the level number
	void SetLevelNumber(int);

	// Method for getting the level number
	int GetLevelNumber() const;
};
