#pragma once
#include "GameObject.h"

class Vehicle : public GameObject
{
public:
	Vehicle(Screen& screen, int vehicle, bool goingLeft, int speed);
	~Vehicle();

	void Update() override;
	void Render() override;

private:
	void vehicleMovement();
};
