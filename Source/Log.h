//Daniel Mardunovich
#pragma once
#include "GameObject.h"
class Log : public GameObject
{
public:
	Log(Screen& screen, int log, bool goingLeft, int speed);
	~Log();

	void Update() override;
	void Render() override;

private:
	void logMovement();
};
