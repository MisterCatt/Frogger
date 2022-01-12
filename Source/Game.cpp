#include "Game.h"

Game::Game(Screen& screen) : m_screen(screen) {
	m_player = new Frog(m_screen);

	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 30));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 30));
	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 30));
	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 30));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 30));

	{
		int temp = 60;
		for (Vehicle* v : vehicleArray) {
			v->setY(temp);
			temp += 30;
		}
	}

}

void Game::Update() {
	m_player->Update();

	for (Vehicle* v : vehicleArray) {
		v->Update();
		worldWrap(*v);

		onCollision(*v, *m_player);
	}
}

void Game::Render() {
	m_player->Render();

	for (Vehicle* v : vehicleArray) {
		v->Render();
	}
}

void Game::onCollision(GameObject& obj1, GameObject& obj2) {
	if ((obj1.getX() <= obj2.getMaxX() && obj1.getMaxX() >= obj2.getX()) &&
		(obj1.getY() <= obj2.getMaxY() && obj1.getMaxY() >= obj2.getY())) {
		std::cout << "hit!" << std::endl;
	}
}

void Game::worldWrap(GameObject& vehicle) {
	if (vehicle.getX() < -61) {
		vehicle.setX(m_screen.GetWindowWidth()+60);
	}
	if (vehicle.getX() > m_screen.GetWindowWidth() + 60)
		vehicle.setX(-60);
}

void Game::runGame() {
	this->Render();
	this->Update();
}

Game::~Game() {

}