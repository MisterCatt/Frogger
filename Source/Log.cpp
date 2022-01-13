#include "Log.h"

Log::Log(Screen& screen, int log = 0,bool goingLeft = false, int speed = 30) : GameObject(screen) {
	m_name = "Log";

	m_speed = speed;

	if (goingLeft)
		moving = Direction::left;
	else
		moving = Direction::right;

	if (log == 0) {
		m_sprite = m_screen.LoadSprite("assets/log100.png");
	}
	else if (log == 1) {
		m_sprite = m_screen.LoadSprite("assets/log150.png");
	}
	else {
		m_sprite = m_screen.LoadSprite("assets/log200.png");
	}

}

void Log::Update() {
	updateCoords();
	for(int i = 0; i < m_speed; i++)
	logMovement();
}

void Log::Render() {
	m_screen.DrawSprite(m_sprite);
}

void Log::logMovement() {
	switch (moving)
	{
	case Log::Direction::up:
		setY(getY() - 1);
		break;
	case Log::Direction::down:
		setY(getY() + 1);
		break;
	case Log::Direction::left:
		setX(getX() - 1);
		break;
	case Log::Direction::right:
		setX(getX() + 1);
		break;
	case Log::Direction::stopped:
		break;
	default:
		break;
	}
}