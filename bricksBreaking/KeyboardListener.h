#include "Observer.h"
#include <SDL.h>

#ifndef KEYBOARD_LISTENER_H_
#define KEYBOARD_LISTENER_H_

class Controllable;

namespace Keyboard {

	enum Key {
		KEY_PRESSED_UP,
		KEY_PRESSED_DOWN,
		KEY_PRESSED_LEFT,
		KEY_PRESSED_RIGHT,
		KEY_PRESSED_NUMPAD2,
		KEY_PRESSED_NUMPAD4,
		KEY_PRESSED_NUMPAD6,
		KEY_PRESSED_NUMPAD8,
		KEY_PRESSED_ENTER,
		KEY_PRESSED_SPACEBAR,
		UNKNOWN_KEY
	};

	typedef std::pair<Keyboard::Key, std::vector<Controllable&>> controllablePair;
	typedef std::vector<controllablePair> pairsVector;

	class KeyboardListener {
	public:
		KeyboardListener(Observer& obs);
		void addControllable(Controllable& cont, std::vector<Keyboard::Key> vec);
		void reportKeyPress(SDL_Event& keyEvent);
	private:
		Observer& obs;
		pairsVector controlList;
	};
	
}

#endif