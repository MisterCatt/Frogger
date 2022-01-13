#include "GameObject.h"

GameObject::GameObject(Screen& screen) : m_screen(screen)
{
	moving = Direction::stopped;
	isMoving = false;
	movingCounter = m_sprite.texture.height;
	m_speed = 1;
}

GameObject::~GameObject()
{
}

int GameObject::getX() {
	return m_position.x;
}

int GameObject::getY() {
	return m_position.y;
}

int GameObject::getMaxX() {
	return m_position.x + m_sprite.texture.width;
}

int GameObject::getMaxY() {
	return m_position.y + m_sprite.texture.height;
}

void GameObject::setX(int x) {
	m_position.x = x;
}

void GameObject::setY(int y) {
	m_position.y = y;
}

void GameObject::updateCoords() {
	m_sprite.position.x = m_position.x;
	m_sprite.position.y = m_position.y;
}

int GameObject::getSpeed() {
	return m_speed;
}

void GameObject::setSpeed(int speed) {
	m_speed = speed;
}

std::string GameObject::getName() {
	return m_name;
}

bool GameObject::goingLeft() {
	if (moving == Direction::left)
		return true;
	else
		return false;
}