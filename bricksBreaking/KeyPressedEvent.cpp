#include "stdafx.h"
#include "KeyPressedEvent.h"
using namespace Game;
using namespace Keyboard;

KeyPressedEvent::KeyPressedEvent(const KeyPressedEvent& other) : control(other.control), key(other.key){
}

KeyPressedEvent::KeyPressedEvent(Keyboard::Controllable& control, Key key) : control(control), key(key) {
}

KeyPressedEvent::~KeyPressedEvent() {
}

KeyPressedEvent* KeyPressedEvent::clone() {
	return new KeyPressedEvent(*this);
}

void KeyPressedEvent::handle() {
	control.react(key);
}