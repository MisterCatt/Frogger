//Daniel Mardunovich
#include "Game.h"

Game::Game(Screen& screen) : m_screen(screen) {
	m_player = new Frog(m_screen);

	for (int i = 0; i < 3; i++) {
		froglife.push_back(m_screen.LoadSprite("assets/tempfrogup.png"));
	}

	{
		int tempX = m_screen.GetWindowWidth() / 5;
		for (Sprite& s : froglife) {
			s.position.x = tempX;
			s.position.y = m_screen.GetWindowHeight() - 30;
			s.scale /= 2;
			tempX += 30;
		}
	}
	titleScreenCounter = 300;
	isTitlescreenUp = true;
	titleScreen = m_screen.LoadSprite("assets/titlescreen.png");

	crash = m_screen.LoadSound("assets/Crash.ogg");

	//Eric Skiff - Song Name - A Night Of Dizzy Spells - Available at http://EricSkiff.com/music
	music = m_screen.LoadSound("assets/music.ogg");

	winPoints = 0;
	lives = 3;
	alive = true;

	hasWon = false;

	for (int i = 0; i < 5; i++)
		wpsArray.push_back(new WinPosition(m_screen));

	vehicleArray.push_back(new Vehicle(m_screen, 0, true, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 0, true, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 0, true, 3));

	vehicleArray.push_back(new Vehicle(m_screen, 1, false, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, false, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, false, 3));

	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 2, true, 2));

	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 1));
	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 1));
	vehicleArray.push_back(new Vehicle(m_screen, 0, false, 1));

	vehicleArray.push_back(new Vehicle(m_screen, 2, false, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 2, false, 2));
	vehicleArray.push_back(new Vehicle(m_screen, 2, false, 2));

	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));
	vehicleArray.push_back(new Vehicle(m_screen, 1, true, 3));

	logArray.push_back(new Log(m_screen, 0, false, 1));
	logArray.push_back(new Log(m_screen, 0, false, 1));
	logArray.push_back(new Log(m_screen, 0, false, 1));

	logArray.push_back(new Log(m_screen, 1, true, 2));
	logArray.push_back(new Log(m_screen, 1, true, 2));
	logArray.push_back(new Log(m_screen, 1, true, 2));

	logArray.push_back(new Log(m_screen, 2, false, 3));
	logArray.push_back(new Log(m_screen, 2, false, 3));
	logArray.push_back(new Log(m_screen, 2, false, 3));

	logArray.push_back(new Log(m_screen, 0, true, 1));
	logArray.push_back(new Log(m_screen, 0, true, 1));
	logArray.push_back(new Log(m_screen, 0, true, 1));

	logArray.push_back(new Log(m_screen, 1, false, 2));
	logArray.push_back(new Log(m_screen, 1, false, 2));
	logArray.push_back(new Log(m_screen, 1, false, 2));

	logArray.push_back(new Log(m_screen, 2, true, 3));
	logArray.push_back(new Log(m_screen, 2, true, 3));
	logArray.push_back(new Log(m_screen, 2, true, 3));

	{
		int y = 100;
		int x = 0;
		int temp = 0;
		for (int i = 0; i < logArray.size(); i++) {
			temp++;
			logArray.at(i)->setY(y);
			logArray.at(i)->setX(x);
			x += 300;
			if (temp == 3) {
				y += 50;
				x = 0;
				temp = 0;
			}			
		}
	}

	{
		int y = 50*9;
		int x = 0;
		int temp = 0;
		for (int i = 0; i < vehicleArray.size(); i++) {
			temp++;
			vehicleArray.at(i)->setY(y);
			vehicleArray.at(i)->setX(x);
			x += 300;
			if (temp == 3) {
				y += 50;
				x = 0;
				temp = 0;
			}
		}
	}
}

void Game::Update() {
	if (!isTitlescreenUp) {
		m_screen.PlaySound(music);
		if (!hasWon) {
			if (alive) {
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

				for (WinPosition* w : wpsArray)
					winCollision(*w, *m_player);

				if (m_player->getY() >= 0 && m_player->getY() <= 50 * 7 && m_player->hasStopped() && !m_player->frogOnLog()) {
					std::cout << "ded" << std::endl;
					getHit();
				}

				if (winPoints == 5) {
					hasWon = true;
				}
				if (lives == 0) {
					alive = false;
				}

				frogOutsideScreen(*m_player);
			}
		}
	}
	else
	{
		titleScreenCounter--;
		if (titleScreenCounter <= 0) {
			isTitlescreenUp = false;
		}
	}
}

void Game::Render() {
	if (!isTitlescreenUp) {
		if (!hasWon) {
			if (alive) {
				drawGameBoard();

				for (Log* l : logArray) {
					l->Render();
				}

				m_player->Render();

				for (Vehicle* v : vehicleArray) {
					v->Render();
				}
			}
			else {
				Loose();
			}
		}
		else {
			Win();
		}
	}
	else {
		drawTitleScreen();
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
		for (WinPosition* w : wpsArray) {

				w->setX(temp);
				w->setY(40);
				temp += m_screen.GetWindowWidth()/6.45;
				w->Update();
				w->Render();
			}
	}

	m_screen.DrawText(m_screen.GetWindowWidth() / 50, m_screen.GetWindowHeight() - 30, { 255,255,255 }, "Lives: ", 3);

		
	for (int i = 0; i < lives; i++) {
		m_screen.DrawSprite(froglife.at(i));
		}
}

void Game::onCollision(GameObject& obj1, Frog& frog) {
	if ((obj1.getX() <= frog.getMaxX() && obj1.getMaxX() >= frog.getX()) &&
		(obj1.getY()+1 <= frog.getMaxY()-1 && obj1.getMaxY()-1 >= frog.getY()+1)) {
		if (obj1.getName() == "Vehicle") {
			if (frog.hasStopped()) {
				getHit();
				m_screen.PlaySound(crash);
			}
		}
		if (obj1.getName() == "Log") {
			if (!obj1.goingLeft()) {
				if (frog.hasStopped()) {
					frog.setOnLog(true);
					for (int i = 0; i < obj1.getSpeed(); i++)
						frog.setX(frog.getX() + 1);
				}
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

void Game::winCollision(WinPosition& wps, Frog& frog) {
	if ((wps.getX() <= frog.getMaxX() && wps.getMaxX() >= frog.getX()) &&
		(wps.getY() + 1 <= frog.getMaxY() - 1 && wps.getMaxY() - 1 >= frog.getY() + 1)) {
		if (frog.hasStopped() && !wps.filled()) {
			std::cout << "win" << std::endl;
			wps.setFilled();
			winPoints++;

			m_player->setX(m_screen.GetWindowWidth()/2 - (m_player->getMaxX() - m_player->getX()));
			m_player->setY(m_screen.GetWindowHeight()-(m_player->getMaxY() - m_player->getY()));
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

void Game::Win() {
	m_screen.DrawText(m_screen.GetWindowWidth() / 2 -240, m_screen.GetWindowHeight() / 2, { 255,255,255 }, "You win!", 5);
}void Game::Loose() {
	m_screen.DrawText(m_screen.GetWindowWidth() / 2 - 330, m_screen.GetWindowHeight() / 2, { 255,255,255 }, "You lost :(", 5);
}



void Game::runGame() {
	this->Render();
	this->Update();
}

Game::~Game() {

}

void Game::drawTitleScreen() {
	m_screen.DrawSprite(titleScreen);
}

void Game::frogOutsideScreen(Frog& frog) {
	if (frog.getX() < 0-(frog.getMaxX()-frog.getX())) {
		getHit();
	}
	else if (frog.getX() > m_screen.GetWindowWidth() + (frog.getMaxX() - frog.getX())) {
		getHit();
	}
}