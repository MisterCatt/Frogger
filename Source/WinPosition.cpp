#include "WinPosition.h"

WinPosition::WinPosition(Screen& screen) : GameObject(screen) {
	m_sprite = m_screen.LoadSprite("assets/winpos.png");

	isFilled = false;
}

WinPosition::~WinPosition() {

}

void WinPosition::Update() {
	updateCoords();
}

void WinPosition::Render() {
	m_screen.DrawSprite(m_sprite);
}

void WinPosition::setFilled() {
		m_sprite = m_screen.LoadSprite("assets/frogwin.png");
		isFilled = true;
}

bool WinPosition::filled() {
	return isFilled;
}