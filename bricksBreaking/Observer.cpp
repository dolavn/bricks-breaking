#include "Observer.h"

/* empty constructor */
Observer::Observer():events() {
} 

/* copy constructors - deep coping the vector of other */
Observer::Observer(const Observer& other) : events() {
	for (unsigned int i = 0; i < other.events.size(); i++) {
		Game::Event* add = other.events[i]->clone();
		events.push_back(add);
	}
} 

/*deletes this Observer and copies the events in other's vector to new one and assing it to this*/
Observer& Observer::operator=(const Observer& other) {
	if (this == &other) {
		return *this;
	}
	clear();
	events = std::vector<Game::Event*>();
	for (unsigned int i = 0; i < other.events.size(); i++) {
		Game::Event* add = other.events[i]->clone();
		events.push_back(add);
	}
	return *this;
}

void Observer::clear() {
	for (unsigned int i = 0; i < events.size(); i++) {
		if (events[i] != nullptr) {
			delete(events[i]);
			events[i] = nullptr;
		}
	}
}

void Observer::notifyEvent(Game::Event& event) {
	Game::Event* add = event.clone();
	events.push_back(add);
}

void Observer::handleEvents() {
	//taltul
}

Observer::~Observer() {
	clear();
}

