#include "WinPosition.h"

WinPosition::WinPosition(Screen& screen) : GameObject(screen) {
	m_sprite = m_screen.LoadSprite("assets/winpos.png");

	isFilled = false;
}

void WinPosition::Update() {
	updateCoords();
}

void WinPosition::Render() {
	m_screen.DrawSprite(m_sprite);
}

void WinPosition::setFilled() {
	if (!isFilled) {
		m_sprite = m_screen.LoadSprite("test.bmp");
		isFilled = true;
	}
}

bool WinPosition::getFilled() {
	return isFilled;
}