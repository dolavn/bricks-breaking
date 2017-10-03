#include "stdafx.h"
#include "PlayerSurface.h"
#include "Rectangle.h"
#include "KeyboardListener.h"
#include "Point.h"
#include <vector>

PlayerSurface::PlayerSurface(int x, int y) :GameObject(x, y), Controllable() {
	addShape(Rectangle(x, y, SURFACE_WIDTH, SURFACE_HEIGHT, SURFACE_COLOR));
}

PlayerSurface::PlayerSurface(const PlayerSurface& other) : GameObject(other), Controllable(other) {

}

GameObject* PlayerSurface::clone() {
	return new PlayerSurface(*this);
}

void PlayerSurface::subscribe(Engine& engine) {
	using namespace Keyboard;
	KeyboardListener& listener = engine.getListener();
	std::vector<Keyboard::Key> keyVector;
	keyVector.push_back(KEY_PRESSED_LEFT);
	keyVector.push_back(KEY_PRESSED_RIGHT);
	listener.addControllable(this, keyVector);
}

void PlayerSurface::react(Keyboard::Key key) {
	using namespace Keyboard;
	Point location = getLocation();
	int x = location.getX();
	int y = location.getY();
	if (key == KEY_PRESSED_LEFT) {
		x = x - SURFACE_SPEED;
	}
	if (key == KEY_PRESSED_RIGHT) {
		x = x + SURFACE_SPEED;
	}
	setLocation(x, y);
}

void PlayerSurface::moveObject() {
	clearShapes();
	Point location = getLocation();
	addShape(Rectangle(location.getX(), location.getY(), SURFACE_WIDTH, SURFACE_HEIGHT, SURFACE_COLOR));
}