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

	typedef std::vector<Keyboard::Controllable&> controllableVec;
	typedef std::pair<Keyboard::Key, controllableVec> controllablePair;
	typedef std::vector<controllablePair> pairsVector;

	class KeyboardListener {
	public:
		KeyboardListener(Observer& obs);
		/**
		whenever during the game the player presses any key on the keyboard it will be reported to the observer
		by creating a keyPressedEvent, that way the observer can handel the event and react to this in the game
		(for example: moving the surface left when the left key is pressed)
		*/
		void reportKeyPress(SDL_Event& keyEvent);
		/**
		in case of adding a controllable item to the game, this method adds to the controlList
		all the keys that are controling this object

		@params cont - a Controllable object
		vec - a vector with all the keys that are operating this object
		*/
		void addControllable(Controllable& cont, std::vector<Keyboard::Key> vec);
	private:
		Observer& obs;
		pairsVector controlList;
	};
	
}

#endif