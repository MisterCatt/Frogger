//Daniel Mardunovich
#include "Screen.h"
#include "Game.h"

int screenWidth = 1000;
int screenHeight = 1000;

int main(int argc, char** argv)
{
	Screen screen(screenWidth, screenHeight, "Galba");
	Game* frogger = new Game(screen);

#pragma endregion;

 	while (screen.IsOpen())
	{
		screen.Clear();
		frogger->runGame();
		screen.Display();
	}
	return 0;
}