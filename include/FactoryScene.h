#pragma once
#include "../include/IScene.h"
#include "../include/Player.h"
#include "../include/Levels.h"
#include <memory>

class GameScene;							    // Forward declaration: GameScene statement for statements in this code | The "GameScene.h" in "FactoryScene.cpp"
											    
class FactoryScene {						    
											    
private:									    
	Player					   player;		    
	Level					   level;		    
	std::unique_ptr<GameScene> game_scene;	    // Use of unique_ptr to control GameScene type instances
	int						   level_number;    // With numerical level for switching between levels	

public:
	// Constructor factory in main
	FactoryScene(Player& player, Level& level);

	// This method is used in the main loop of the game : Level chage
	void Update(SDL_Renderer*,Camera&,int,int);

	// Method for setting the level number
	void SetLevelNumber(int);

	// Method for getting the level number
	int GetLevelNumber() const;
};
