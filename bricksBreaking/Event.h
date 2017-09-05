/**
	An abstract class for describing any event
	which is happenning in the game. Each event is handeled by the
	Observer.

	@author Dolav Nitay
	@version 1.0
	@see Observer
*/
#ifndef EVENT_H_
#define EVENT_H_
class GameObject;

namespace Game {
	class Event {
	public:
		/**
			Creates a new empty Event object.
		*/
		Event(); 

		/**
			Deep copies an existing Event object

			@param other The other event object.
		*/
		Event(const Event& other); 

		/**
			An assignment operator, returns a deep copied copy 
			of another event.

			@param other The other event object.
			@returns A deep copied copy of the other event.
		*/
		Event& operator=(const Event& other);

		/**
			Destroys this event object.
		*/
		virtual ~Event(); 

		/**
			Activates this event, a pure virtual function.
		*/
		virtual void act() = 0; 
	private:
	};
}

#endif
