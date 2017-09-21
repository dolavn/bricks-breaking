#include "Engine.h"

#ifndef CONTROLLABLE_H_
#define CONTROLLABLE_H_

namespace Engine {
	class Controllable {
		public:
			/**
			Copy constructor, deep copies another Controllable object.

			@param other The other Controllable object
			*/
			Controllable(const Controllable& other);
			/**
			pure virtual function that reacts for every command from the keyboard 
			and effects the actions of the controllable object
			*/
			virtual void react(Engine::Key key) = 0;
	private:

	};
}
#endif
