#include "Game.h"

Game::Game(Screen& screen) : m_screen(screen) {
	m_player = new Frog(m_screen);

	winPoints = 0;
	lives = 3;
	alive = true;

	hasWon = false;

	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));

	logArray.push_back(new Log(m_screen,0,false,3));
	logArray.push_back(new Log(m_screen,1,true,2));
	logArray.push_back(new Log(m_screen,2,false,1));
	logArray.push_back(new Log(m_screen,0,true,3));
	logArray.push_back(new Log(m_screen,1,false,2));
	logArray.push_back(new Log(m_screen,2,false,1));

	{
		int temp = 100;
		for (Log* l : logArray) {
			l->setY(temp);
			temp += 50;
		}
	}

	{
		int temp = 50*9;
		for (Vehicle* v : vehicleArray) {
			v->setY(temp);
			temp += 50;
		}
	}

}

void Game::Update() {
	m_player->Update();
	m_player->setOnLog(false);

	for (Log* l : logArray) {
		l->Update();
		worldWrap(*l);

		onCollision(*l, *m_player);
	}

	for (Vehicle* v : vehicleArray) {
		v->Update();
		worldWrap(*v);

		onCollision(*v, *m_player);
	}

	if (m_player->getY() >= 100 && m_player->getY() <= 50*7 && m_player->hasStopped() && !m_player->frogOnLog()) {
		getHit();
	}
}

void Game::Render() {
	drawGameBoard();
	

	for (Log* l : logArray) {
		l->Render();
	}

	m_player->Render();

	for (Vehicle* v : vehicleArray) {
		v->Render();
	}
}

void Game::drawGameBoard() {
	m_screen.DrawRectangle(0, 0, m_screen.GetWindowWidth(), 100, {0,255,0});
	m_screen.DrawRectangle(0, 100, m_screen.GetWindowWidth(), 50 * 6, {0, 0, 255});
	m_screen.DrawRectangle(0, 50 * 8, m_screen.GetWindowWidth(), 50, { 128,0,128 });
	m_screen.DrawRectangle(0, 50 * 9, m_screen.GetWindowWidth(), 50 * 7, {220,220,220});
	m_screen.DrawRectangle(0, 50*15,m_screen.GetWindowWidth(), 50, {128,0,128});

	{
		int temp = m_screen.GetWindowWidth() / 6.45;
		for (int i = 0; i < 5; i++) {
				m_screen.DrawRectangle(temp, 40, 70, 60);
				temp += m_screen.GetWindowWidth()/6.45;
			}
	}

}

void Game::onCollision(GameObject& obj1, Frog& frog) {
	if ((obj1.getX() <= frog.getMaxX() && obj1.getMaxX() >= frog.getX()) &&
		(obj1.getY()+1 <= frog.getMaxY()-1 && obj1.getMaxY()-1 >= frog.getY()+1)) {
		if (obj1.getName() == "Vehicle") {
			getHit();
		}
		if (obj1.getName() == "Log") {
			if (!obj1.goingLeft())
				if (frog.hasStopped()) {
					frog.setOnLog(true);
					for (int i = 0; i < obj1.getSpeed(); i++)
						frog.setX(frog.getX() + 1);
				}
			else
					if (frog.hasStopped()) {
						frog.setOnLog(true);
						for (int i = 0; i < obj1.getSpeed(); i++)
							frog.setX(frog.getX() - 1);
					}
		}
	}
}

void Game::getHit() {
	std::cout << "dead" << std::endl;
	delete m_player;

	m_player = new Frog(m_screen);

	lives--;
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