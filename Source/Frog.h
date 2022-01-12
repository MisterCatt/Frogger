#pragma once
#include "GameObject.h"
class Frog : public GameObject
{
public:
	Frog(Screen& screen);
	~Frog();

	void input();
	void Update() override;
	void Render() override;

	bool getAlive();
	void setAlive(bool aliveState);

private:
	bool alive;

	void movingFrog();

	void onWater() override;
	
};
