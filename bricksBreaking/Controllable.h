#include "Engine.h"
#include "KeyboardListener.h"

#ifndef CONTROLLABLE_H_
#define CONTROLLABLE_H_

namespace Keyboard {
	class Controllable {
		public:
			/**
				Creates a new Controllable object.
			*/
			Controllable();
			/**
				Copy constructor, deep copies another Controllable object.

				@param other The other Controllable object
			*/
			Controllable(const Controllable& other);
			/**
				Pure virtual function that reacts for every command from the keyboard 
				and effects the actions of the controllable object

				@param key The key that was pressed.
			*/
			virtual void react(Keyboard::Key key) = 0;
	private:

	};
}
#endif
