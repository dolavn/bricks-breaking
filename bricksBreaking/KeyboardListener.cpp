#include "stdafx.h"
#include "KeyboardListener.h"
#include "KeyPressedEvent.h"

namespace Keyboard {
	KeyboardListener::KeyboardListener(Observer& obs) : obs(obs), controlList(){
	}

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
		for (unsigned int i = 0; i < controlList.size(); i++) {
			if (keyPressed == controlList[i].first) {
				controllablePair& currPair = controlList[i];
				controllableVec& currVec = currPair.second;
				for (unsigned int j = 0; j < currVec.size(); j++) {
					Game::KeyPressedEvent kpe = Game::KeyPressedEvent(*currVec[j], keyPressed);
					obs.notifyEvent(kpe);
				}
			}
		}
	} //reportKeyPress

	void KeyboardListener::addControllable(Controllable* cont, std::vector<Keyboard::Key> vec) {
		for (unsigned int i = 0; i < vec.size(); i++) {
			for (unsigned j = 0; j < controlList.size(); j++) {
				if (vec[i] == controlList[j].first) {
					controlList[j].second.push_back(cont);
				}
			}
		}
	} //addControllable

}