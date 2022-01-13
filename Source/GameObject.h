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

	virtual int getSpeed();
	virtual void setSpeed(int speed);

	virtual int getMaxX();
	virtual int getMaxY();

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual std::string getName();
	virtual bool goingLeft();

protected:
	Vector2 m_position;
	Sprite m_sprite;

	Screen& m_screen;
	
	std::string m_name;

	bool isMoving;
	int movingCounter;

	int m_speed;

	enum class Direction { up, down, left, right, stopped } moving;

	virtual void updateCoords();
};