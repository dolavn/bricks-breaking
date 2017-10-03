#include "Event.h"
#include "Controllable.h"
#include "KeyboardListener.h"

#ifndef KEYPRESSEDEVENT_H_
#define KEYPRESSEDEVENT_H_

namespace Game {
	class KeyPressedEvent:public Event {
	public:
		/**
			copy constructor

			@param other The other KeyPressedEvent object
		*/
		KeyPressedEvent(const KeyPressedEvent& other);
		/**
			constructor

			@param control - the controllablr object, key - the key that was pressed and controls the object
		*/
		KeyPressedEvent(Keyboard::Controllable& control, Keyboard::Key key);
		/**
			destructor
		*/
		virtual ~KeyPressedEvent();
		/**
			execute the pure virtual method of Event. returns a clone of this object
		*/
		KeyPressedEvent* clone();
		/**
			execute the pure virtual method of Event. handels the event
		*/
		void handle();
	private:
		Keyboard::Controllable& control;
		Keyboard::Key key;
	};
}
 
#endif
