#pragma once

#include "Graphics.h"
#include "Text.h"
#include "Shape.h"
#include "GameObject.h"
#include <sstream>
#include <stdint.h>
#include <vector>
/*
This is the main game engine, it handles the graphics,
user input, and all the game objects.
*/

const int TARGET_FPS = 50;
const int TIMER_CYCLE = 25;

class Engine {
public:
	Engine();
	virtual ~Engine();
	void startGame();
	void moveObj();
	void addObject(GameObject& objj);
private:
	SDL_mutex *lock;
	std::vector<GameObject*> gameObjects;
	void runGame();
	void onEvent(SDL_Event* Event);
	static Uint32 timerCallBack(Uint32 interval, void *param);
	bool running;
	Graphics graphics;
	SDL_TimerID timerId;
	void printTimes(int c);
	int timeTxt;
	/*Integers used to measure how much computation time takes each action.*/
	int count = 0;
	int move = 0;
	int drawRun = 0;
	int drawAvg = 0;
	int runAvg = 0;
	int rendAvg = 0;
	int avgFps = 0;
};