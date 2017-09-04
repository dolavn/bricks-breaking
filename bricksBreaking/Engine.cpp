#include "stdafx.h"
#include "Engine.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ball.h"
#include <iostream>

/*
Constructs a game engine object.
*/
Engine::Engine():graphics(640,480) {
	running = true;
	graphics.addShape(Rectangle(10, 10, 50, 10, Colors::ORANGE));
	timeTxt = graphics.addShape(Text(10, 50, "0", Colors::YELLOW));
	addObject(Ball(100,200));
	lock = SDL_CreateMutex();
}

void Engine::startGame() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	graphics.init(); //initializes the graphics
	timerId = SDL_AddTimer(TIMER_CYCLE, Engine::timerCallBack, this);
	SDL_Event Event;
	Uint32 ticks = SDL_GetTicks();
	int c = 0;
	/*
	This loop renders the frames
	*/
	while (running) {
		Uint32 startTicks = SDL_GetTicks(); //Measures time in the beginning of rendering current frame
		c++;
		/*
		Checks for events.
		*/
		while (SDL_PollEvent(&Event) != 0) {
			onEvent(&Event);
		}
		graphics.removeShape(timeTxt);
		//text 
		Uint32 lastFrame = SDL_GetTicks() - ticks; //Measures time past from last frame render time.
		if (lastFrame == 0) {
			lastFrame = 1;
		}
		int curr_fps = 1000 / lastFrame; //Measures current fps.
		avgFps = avgFps + curr_fps; //Adds current fps to the sum of all fps.
		ticks = SDL_GetTicks();
		std::stringstream ss;
		ss << curr_fps;
		std::string output = ss.str();
		timeTxt = graphics.addShape(Text(10, 50, output, Colors::YELLOW));
		Uint32 runG = SDL_GetTicks();
		runGame();
		runG = SDL_GetTicks() - runG;
		runAvg = runAvg + runG;
		Uint32 dra = SDL_GetTicks();
		graphics.draw();
		dra = SDL_GetTicks() - dra;
		drawAvg = drawAvg + dra;
		Uint32 rend = SDL_GetTicks();
		graphics.render();
		rend = SDL_GetTicks() - rend;
		rendAvg = rendAvg + rend;
		int waitTime = 0;
		Uint32 finTicks = SDL_GetTicks();
		if (finTicks-startTicks < (1000 / TARGET_FPS)) {
			waitTime = (1000 / TARGET_FPS) - finTicks+startTicks;
		}
		SDL_Delay(waitTime);
		running = c < 1000;
	}
	printTimes(c);
	int i;
	std::cin >> i;
}

void Engine::printTimes(int c) {
	runAvg = runAvg / c;
	drawAvg = drawAvg / c;
	rendAvg = rendAvg / c;
	move = move / c;
	drawRun = drawRun / c;
	avgFps = avgFps / c;
	std::cout << "run:";
	std::cout << runAvg << std::endl;
	std::cout << "draw:";
	std::cout << drawAvg << std::endl;
	std::cout << "rend:";
	std::cout << rendAvg << std::endl;
	std::cout << "move:"; //move 39
	std::cout << move << std::endl;
	std::cout << "drawRun:"; //draw run 17
	std::cout << drawRun << std::endl;
	std::cout << "average fps:";
	std::cout << avgFps << std::endl;
}

void Engine::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT)
		running = false;
}

void Engine::addObject(GameObject& obj) {
	SDL_LockMutex(lock);
	GameObject* addObj = obj.clone();
	gameObjects.push_back(addObj);
	SDL_UnlockMutex(lock);
}

Uint32 Engine::timerCallBack(Uint32 interval, void *param) {
	Engine* eng = static_cast<Engine*>(param);
	if (eng->running) {
		eng->moveObj();
	}
	eng->timerId = SDL_AddTimer(TIMER_CYCLE, Engine::timerCallBack, eng);
	return 0;
}

void Engine::moveObj() {
	SDL_LockMutex(lock);
	for (unsigned int i = 0; i < gameObjects.size(); i = i + 1) {
		Uint32 mov = SDL_GetTicks();
		GameObject& curr = *(gameObjects[i]);
		curr.move();
		mov = SDL_GetTicks() - mov;
		move = move + mov;
	}
	SDL_UnlockMutex(lock);
}

void Engine::runGame() {
	SDL_LockMutex(lock);
	for (unsigned int i = 0; i < gameObjects.size(); i = i + 1) {
		GameObject& curr = *(gameObjects[i]);
		Uint32 dra = SDL_GetTicks();
		curr.draw(graphics);
		dra = SDL_GetTicks() - dra;
		drawRun = drawRun + dra;
	}
	SDL_UnlockMutex(lock);
}

Engine::~Engine() {
	SDL_LockMutex(lock);
	for (unsigned int i = 0; i < gameObjects.size(); i = i + 1) {
		delete(gameObjects[i]);
	}
	SDL_UnlockMutex(lock);
	SDL_DestroyMutex(lock);
}