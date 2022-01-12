#pragma once
#include "Screen.h"
#include <iostream>

class GameObject
{
public:
	GameObject(Screen& screen);
	~GameObject();

	virtual int getX();
	virtual int getY();
	virtual void setX(int x);
	virtual void setY(int y);

	virtual int getMaxX();
	virtual int getMaxY();

	virtual void onWater() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	Vector2 m_position;
	Sprite m_sprite;

	Screen& m_screen;
	
	std::string name;

	bool isMoving;
	int movingCounter;

	enum class Direction { up, down, left, right, stopped } moving;

	virtual void updateCoords();
};