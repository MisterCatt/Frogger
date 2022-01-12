#include "Game.h"

Game::Game(Screen& screen) : m_screen(screen) {
	m_player = new Frog(m_screen);
}

void Game::Update() {
	m_player->Update();
}

void Game::Render() {
	m_player->Render();
}

void Game::onCollision() {

}

void Game::runGame() {
	this->Render();
	this->Update();
}

Game::~Game() {

}