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

	bool hasStopped();

	bool frogOnLog();
	void setOnLog(bool frogOnLog);

private:
	bool alive;
	bool onLog;
	int startSpeed;

	void movingFrog();

	void onWater();
	
};
