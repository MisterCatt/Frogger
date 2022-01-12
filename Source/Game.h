#pragma once
#include "Frog.h"
#include "Vehicle.h"
#include <vector>

class Game
{
private:
	Screen& m_screen;
	Frog* m_player;

	std::vector<Vehicle*> vehicleArray;

	void Update();
	void Render();
	void onCollision(GameObject& obj1, GameObject& obj2);
	
	void worldWrap(GameObject& vehicle);

public:
	Game(Screen& screen);
	~Game();
	void runGame();
};
