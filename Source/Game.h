#pragma once
#include "Frog.h"
#include "Vehicle.h"
#include <vector>
#include "Log.h"
#include "WinPosition.h"

class Game
{
private:
	Screen& m_screen;
	Frog* m_player;

	Sound crash;
	Sound music;

	Sprite titleScreen;

	std::vector<Vehicle*> vehicleArray;
	std::vector<Log*> logArray;
	std::vector<WinPosition*> wpsArray;

	int lives;
	bool alive;

	int winPoints;
	bool hasWon;

	int titleScreenCounter;
	bool isTitlescreenUp;

	void Win();
	void Loose();

	void getHit();

	void Update();
	void Render();
	void onCollision(GameObject& obj1, Frog& frog);
	void winCollision(WinPosition& wps, Frog& frog);
	
	void worldWrap(GameObject& vehicle);

	void drawGameBoard();
	void drawTitleScreen();

public:
	Game(Screen& screen);
	~Game();
	void runGame();
};
