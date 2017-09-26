#include "stdafx.h"
#include "KeyboardListener.h"

namespace Keyboard {
	void KeyboardListener::reportKeyPress(SDL_Event& keyEvent) {
		Key keyPressed;
		switch (keyEvent.key.keysym.sym) {
		case SDLK_UP:
			keyPressed = KEY_PRESSED_UP;
			break;
		case SDLK_DOWN:
			keyPressed = KEY_PRESSED_DOWN;
			break;
		case SDLK_LEFT:
			keyPressed = KEY_PRESSED_LEFT;
			break;
		case SDLK_RIGHT:
			keyPressed = KEY_PRESSED_RIGHT;
			break;
		case SDLK_KP_2:
			keyPressed = KEY_PRESSED_NUMPAD2;
			break;
		case SDLK_KP_4:
			keyPressed = KEY_PRESSED_NUMPAD4;
			break;
		case SDLK_KP_6:
			keyPressed = KEY_PRESSED_NUMPAD6;
			break;
		case SDLK_KP_8:
			keyPressed = KEY_PRESSED_NUMPAD8;
			break;
		case SDLK_SPACE:
			keyPressed = KEY_PRESSED_SPACEBAR;
			break;
		case SDLK_RETURN:
			keyPressed = KEY_PRESSED_ENTER;
			break;
		default:
			keyPressed = UNKNOWN_KEY;
			break;
		}

	}
}