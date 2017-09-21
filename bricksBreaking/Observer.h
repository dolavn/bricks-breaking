#include <vector>
#include "Event.h"

#ifndef OBSERVER_H_
#define OBSERVER_H_


/**
	The observer class is tasked with handling all the events in the game.
	Each event that happened is reported to the Observer,
	which in turn activates each one of them.

	@author Dolav Nitay
	@author Tal Lavon
	@version 1.0
*/
class Observer {
public:
	/**
		Creates a new empty Event object.
	*/
	Observer(); 
	/**
		Deep copies an existing Observer object

		@param other The other observer object.
	*/
	Observer(const Observer& other); 
	/**
		An assignment operator, returns a deep copied copy
		of another observer.
		@param other The other observer object.
		@return A deep copied copy of the other observer.
	*/
	Observer& operator=(const Observer& other); 
	/**
		Destroys this event object.
	*/
	virtual ~Observer(); 
	/**
		This function is used to report an event to the observer.

		@param event The event being reported.
	*/
	void notifyEvent(Game::Event& event); 
	/**
		Handles all the events reported to this observer.
	*/
	void handleEvents();
private:
	std::vector<Game::Event*> events; //A vector of all the events in the game.
	void clear(); //Clears the memory
};

#endif