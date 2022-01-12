#include "Vehicle.h"

Vehicle::Vehicle(Screen& screen, int vehicle = 0,  bool goingLeft = false, int speed = 30) : GameObject(screen) {
	name = "Vehicle";

	if(vehicle == 0)
	m_sprite = m_screen.LoadSprite("assets/Vehicle1.png");
	else if(vehicle == 1)
	m_sprite = m_screen.LoadSprite("assets/Vehicle2.png");
	else
	m_sprite = m_screen.LoadSprite("assets/Vehicle3.png");

	vehicleSpeed = speed;

	if (goingLeft)
		moving = Direction::left;
	else
		moving = Direction::right;
}

Vehicle::~Vehicle() {

}

void Vehicle::setSpeed(int speed){
	vehicleSpeed = speed;
}

int Vehicle::getSpeed() {
	return vehicleSpeed;
}

void Vehicle::Update() {
	updateCoords();
	vehicleMovement();
}

void Vehicle::Render() {
	m_screen.DrawSprite(m_sprite);
}

void Vehicle::vehicleMovement() {
	switch (moving)
	{
	case Vehicle::Direction::up:
		setY(getY() - 1);
		break;
	case Vehicle::Direction::down:
		setY(getY() + 1);
		break;
	case Vehicle::Direction::left:
		setX(getX() - 1);
		break;
	case Vehicle::Direction::right:
		setX(getX() + 1);
		break;
	case Vehicle::Direction::stopped:
		break;
	default:
		break;
	}
}
void Vehicle::onWater() {
	return;
}