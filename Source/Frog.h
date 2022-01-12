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
	bool onLog;

	void movingFrog();

	void onWater() override;
	
};
