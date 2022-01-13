#pragma once
#include "Frog.h"
#include "Vehicle.h"
#include <vector>
#include "Log.h"

class Game
{
private:
	Screen& m_screen;
	Frog* m_player;

	std::vector<Vehicle*> vehicleArray;
	std::vector<Log*> logArray;

	int lives;
	bool alive;

	int winPoints;
	bool hasWon;

	void win();

	void getHit();

	void Update();
	void Render();
	void onCollision(GameObject& obj1, Frog& obj2);
	
	void worldWrap(GameObject& vehicle);

	void drawGameBoard();

public:
	Game(Screen& screen);
	~Game();
	void runGame();
};
