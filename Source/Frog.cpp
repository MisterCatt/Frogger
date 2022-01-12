#include "Frog.h"

Frog::Frog(Screen& screen) : GameObject(screen)
{
	name = "Player";

	alive = true;
	isMoving = false;
	onLog = false;

	moving = Direction::stopped;
	m_sprite = m_screen.LoadSprite("assets/tempFrog.png");

	movingCounter = m_sprite.texture.height+1;

	setX(m_screen.GetWindowWidth()/2);
	setY(m_screen.GetWindowHeight() - m_sprite.texture.height*3-3);
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

//todo make sure that the character moves its own size in 30 frames
void Frog::Update() {
	updateCoords();
	input();
	if (isMoving) {
		movingCounter--;
	}
	movingFrog();
	if (movingCounter <= 0) {
		isMoving = false;
		moving = Direction::stopped;
		movingCounter = m_sprite.texture.height+1;
	}
}

void Frog::Render() {
	m_screen.DrawSprite(m_sprite);
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