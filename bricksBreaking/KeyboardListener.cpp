#include "stdafx.h"
#include "KeyboardListener.h"

namespace Keyboard {
	void KeyboardListener::reportKeyPress(SDL_Event& keyEvent) {
		Key keyPressed;
		switch (keyEvent.key.keysym.sym) {
		case SDLK_KP_2:
			keyPressed = KEY_PRESSED_NUMPAD2;
			break;
		default:
			keyPressed = UNKNOWN_KEY;
			break;
		}

	}
}