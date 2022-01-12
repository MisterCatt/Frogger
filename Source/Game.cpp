#include "Game.h"

Game::Game(Screen& screen) : m_screen(screen) {
	m_player = new Frog(m_screen);

	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));

	{
		int temp = 100;
		for (Vehicle* v : vehicleArray) {
			v->setY(temp);
			temp += 50;
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
	drawGameBoard();
	m_player->Render();

	for (Vehicle* v : vehicleArray) {
		v->Render();
	}
}

void Game::drawGameBoard() {
	m_screen.DrawRectangle(0, 0, m_screen.GetWindowWidth(), 50, {0,255,0});
	m_screen.DrawRectangle(0, 50, m_screen.GetWindowWidth(), 50 * 8, {0, 0, 255});
	m_screen.DrawRectangle(0, 50 * 8, m_screen.GetWindowWidth(), 50, { 128,0,128 });
	m_screen.DrawRectangle(0, 50 * 9, m_screen.GetWindowWidth(), 50 * 8);
	m_screen.DrawRectangle(0, 50*17,m_screen.GetWindowWidth(), 50, {128,0,128});

}

void Game::onCollision(GameObject& obj1, GameObject& obj2) {
	if ((obj1.getX() <= obj2.getMaxX() && obj1.getMaxX() >= obj2.getX()) &&
		(obj1.getY()+1 <= obj2.getMaxY()-1 && obj1.getMaxY()-1 >= obj2.getY()+1)) {
		std::cout << "hit!" << std::endl;
	}
}

void Game::worldWrap(GameObject& vehicle) {
	if (vehicle.getX() < -120) {
		vehicle.setX(m_screen.GetWindowWidth()+120);
	}
	if (vehicle.getX() > m_screen.GetWindowWidth() + 120)
		vehicle.setX(-120);
}

void Game::runGame() {
	this->Render();
	this->Update();
}

Game::~Game() {

}