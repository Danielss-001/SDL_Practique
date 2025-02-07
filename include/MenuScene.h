#pragma once
#include "../include/Scene.h"

class MenuScene : public Scene{
private:
	Player player;
	Level level;
public:
	void HandleEvents(SDL_Event& event) override;
	void Update() override;
	void Render(SDL_Renderer* renderer) override;  
};