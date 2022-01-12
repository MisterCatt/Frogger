#pragma once
#include "GameObject.h"

class Vehicle : public GameObject
{
public:
	Vehicle(Screen& screen, int vehicle, bool goingLeft, int speed);
	~Vehicle();

	void setSpeed(int speed);
	int getSpeed();

	void Update() override;
	void Render() override;

	void onWater() override;

private:
	int vehicleSpeed;

	void vehicleMovement();
};
