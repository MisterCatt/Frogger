#pragma once
#include "GameObject.h"
class Frog : public GameObject
{
public:
	Frog(Screen& screen);
	~Frog();

	void input();
	void Update();
	void Render();

	bool getAlive();
	void setAlive(bool aliveState);

private:
	bool alive;

	void updateCoords();
	void movingFrog();

	void onWater() override;
	
};
