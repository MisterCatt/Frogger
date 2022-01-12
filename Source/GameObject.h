#pragma once
#include "Screen.h"

class GameObject
{
public:
	GameObject(Screen& screen);
	~GameObject();

	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);

	virtual void onWater() = 0;

protected:
	Vector2 m_position;
	Sprite m_sprite;

	Screen& m_screen;
	
	std::string name;

	bool isMoving;
	int movingCounter;

	enum class Direction { up, down, left, right, stopped } moving;
};