//Daniel Mardunovich
#pragma once
#include "GameObject.h"

class WinPosition : public GameObject
{
public:
	WinPosition(Screen& screen);
	~WinPosition();

	void Update() override;
	void Render() override;

	void setFilled();
	bool filled();

private:
	bool isFilled;
};