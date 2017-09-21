#pragma once

#include "Graphics.h"
#include "Text.h"
#include "Shape.h"
#include "GameObject.h"
#include "CollisionDetector.h"
#include "Observer.h"
#include <sstream>
#include <stdint.h>
#include <vector>


const int TARGET_FPS = 50; //The desired frame per seconds rate
const int TIMER_CYCLE = 25; //The cycle of the timer, in milliseconds

/*
	This is the main game engine, it handles the graphics,
	user input, and all the game objects.

	@author Dolav Nitay
	@version 1.0
*/
class Engine {
public:
	/**
		A constructor for the game engine, creates the engine.
	*/
	Engine();
	/**
		Destructor for the game engine
	*/
	virtual ~Engine();
	/**
		Starts the game
	*/
	void startGame();
	/**
		Moves all the game objects
	*/
	void moveObj();
	/**
		Adds a new GameObject to the game

		@param obj The new GameObject to be added
	*/
	void addObject(GameObject& obj);
	/**
		Adds a collidable to the game

		@param col The collidable to be added
	*/
	void addCollidable(Collidable* col);
private:
	SDL_mutex *lock; //A lock for synchronizing access to the game objects vector
	std::vector<GameObject*> gameObjects; //The game objects vector
	Observer obs;
	CollisionDetector detector;
	void runGame(); //Runs the game
	void onEvent(SDL_Event* Event); //handles sdl event
	static Uint32 timerCallBack(Uint32 interval, void *param); //Call back function to be called each timer cycle
	bool running; //True if and only if the game is running
	Graphics graphics; //The graphics engine of the game
	SDL_TimerID timerId; //The main game timer
	void printTimes(int c);  //Print all the times calculated
	int timeTxt; //The index in which the Text shape which shows the fps, is stored in the graphics engine

	/*****Integers used to measure how much computation time takes each action.*****/
	int count = 0;
	int move = 0;
	int drawRun = 0;
	int drawAvg = 0;
	int runAvg = 0;
	int rendAvg = 0;
	int avgFps = 0;
	/*****End of time computation integers*****/
};