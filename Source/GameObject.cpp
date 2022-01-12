#include "GameObject.h"

GameObject::GameObject(Screen& screen) : m_screen(screen)
{
	
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

void GameObject::setX(int x) {
	m_position.x = x;
}

void GameObject::setY(int y) {
	m_position.y = y;
}