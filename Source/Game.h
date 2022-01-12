#pragma once
#include "Frog.h"

class Game
{
private:
	Screen& m_screen;
	Frog* m_player;

	void Update();
	void Render();
	void onCollision();
	

public:
	Game(Screen& screen);
	~Game();
	void runGame();
};
