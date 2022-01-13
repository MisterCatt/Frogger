//Daniel Mardunovich
#include "Frog.h"

Frog::Frog(Screen& screen) : GameObject(screen)
{
	m_name = "Player";

	isMoving = false;
	onLog = false;

	moving = Direction::stopped;
	m_sprite = m_screen.LoadSprite("assets/tempFrogUp.png");
	jump = m_screen.LoadSound("assets/jump.ogg");

	movingCounter = m_sprite.texture.height;

	setX(m_screen.GetWindowWidth()/2 - m_sprite.texture.width/2);
	setY(m_screen.GetWindowHeight() - m_sprite.texture.height);

	setSpeed(5);

	startSpeed = 2;
}

Frog::~Frog()
{
}

void Frog::input() {
	if (isMoving == false) {
		if (m_screen.IsKeyDown(Key::Up)) {
			isMoving = true;
			moving = Direction::up;
			m_sprite = m_screen.LoadSprite("assets/tempFrogUp.png");
		}
		else if (m_screen.IsKeyDown(Key::Left)) {
			isMoving = true;
			moving = Direction::left;
			m_sprite = m_screen.LoadSprite("assets/tempFrogLeft.png");
		}
		else if (m_screen.IsKeyDown(Key::Right)) {
			isMoving = true;
			moving = Direction::right;
			m_sprite = m_screen.LoadSprite("assets/tempFrogRight.png");
		}
		else if (m_screen.IsKeyDown(Key::Down)) {
			isMoving = true;
			moving = Direction::down;
			m_sprite = m_screen.LoadSprite("assets/tempFrogDown.png");
		}
	}
}

void Frog::movingFrog() {
	switch (moving)
	{
	case Frog::Direction::up:
		setY(getY()-1);
		m_screen.PlaySound(jump);
		break;
	case Frog::Direction::down:
		setY(getY() + 1);
		m_screen.PlaySound(jump);
		break;
	case Frog::Direction::left:
		setX(getX()-1);
		m_screen.PlaySound(jump);
		break;
	case Frog::Direction::right:
		setX(getX() + 1);
		m_screen.PlaySound(jump);
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
		movingCounter-=m_speed;
	}
	for (int i = 0; i < m_speed; i++) {
		movingFrog();
	}
	if (movingCounter <= 0) {
		isMoving = false;
		moving = Direction::stopped;
		movingCounter = m_sprite.texture.height;
	}
}

void Frog::Render() {
	m_screen.DrawSprite(m_sprite);
}

bool Frog::hasStopped() {
	if (moving == Direction::stopped)
		return true;
	else
		return false;
}

bool Frog::frogOnLog() {
	return onLog;
}

void Frog::setOnLog(bool frogOnLog) {
	onLog = frogOnLog;
}
