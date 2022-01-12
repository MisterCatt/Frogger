#include "Frog.h"

Frog::Frog(Screen& screen) : GameObject(screen)
{
	alive = true;
	isMoving = false;
	moving = Direction::stopped;
	m_sprite = m_screen.LoadSprite("assets/tempFrog.png");

	movingCounter = m_sprite.texture.height;

	setX(m_screen.GetWindowWidth()/2);
	setY(m_screen.GetWindowHeight() - m_sprite.texture.height);
}

Frog::~Frog()
{
}

void Frog::input() {
	if (isMoving == false) {
		if (m_screen.IsKeyDown(Key::Up)) {
			isMoving = true;
			moving = Direction::up;
		}
		else if (m_screen.IsKeyDown(Key::Left)) {
			isMoving = true;
			moving = Direction::left;
		}
		else if (m_screen.IsKeyDown(Key::Right)) {
			isMoving = true;
			moving = Direction::right;
		}
		else if (m_screen.IsKeyDown(Key::Down)) {
			isMoving = true;
			moving = Direction::down;
		}
	}
}

void Frog::movingFrog() {
	switch (moving)
	{
	case Frog::Direction::up:
		setY(getY()-1);
		break;
	case Frog::Direction::down:
		setY(getY() + 1);
		break;
	case Frog::Direction::left:
		setX(getX()-1);
		break;
	case Frog::Direction::right:
		setX(getX() + 1);
		break;
	case Frog::Direction::stopped:
		break;
	default:
		break;
	}
}

void Frog::Update() {
	updateCoords();
	input();
	if (isMoving) {
		movingCounter--;
	}
	movingFrog();
	if (movingCounter == 0) {
		isMoving = false;
		moving = Direction::stopped;
		movingCounter = m_sprite.texture.height;
	}
}

void Frog::Render() {
	m_screen.DrawSprite(m_sprite);
}

void Frog::updateCoords() {
	m_sprite.position.x = m_position.x;
	m_sprite.position.y = m_position.y;
}

void Frog::onWater() {
	alive = false; 
}

bool Frog::getAlive() {
	return alive;
}

void Frog::setAlive(bool aliveState) {
	alive = aliveState;
}