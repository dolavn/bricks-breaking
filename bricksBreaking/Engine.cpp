#include "stdafx.h"
#include "Engine.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ball.h"
#include <iostream>

//Constructs a game engine object.
Engine::Engine():graphics(640,480),obs(),detector(obs) {
	running = true;
	graphics.addShape(Rectangle(10, 10, 50, 10, Colors::ORANGE));
	timeTxt = graphics.addShape(Text(10, 50, "0", Colors::YELLOW));
	addObject(Ball(100,200));
	addObject(Ball(100, 400));
	lock = SDL_CreateMutex();
}

//Starts the game
void Engine::startGame() {
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	graphics.init(); //initializes the graphics
	timerId = SDL_AddTimer(TIMER_CYCLE, Engine::timerCallBack, this); //Creates the main timer
	SDL_Event Event;
	Uint32 ticks = SDL_GetTicks(); //Gets current system time
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
		/**** Creates the string stream for the text of the fps****/
		std::stringstream ss;
		ss << curr_fps;
		std::string output = ss.str();
		/**** End of string stream creation ****/
		timeTxt = graphics.addShape(Text(10, 50, output, Colors::YELLOW));
		Uint32 runG = SDL_GetTicks(); //System time before running the game.
		runGame();
		runG = SDL_GetTicks() - runG; //The time it took to run the game.
		runAvg = runAvg + runG; //Adds the time to the average
		Uint32 dra = SDL_GetTicks(); //System time before drawing.
		graphics.draw();
		dra = SDL_GetTicks() - dra; //The time it took to draw.
		drawAvg = drawAvg + dra;//Adds the time to the average
		Uint32 rend = SDL_GetTicks(); //System time before rendering.
		graphics.render();
		rend = SDL_GetTicks() - rend; //The time it took to render
		rendAvg = rendAvg + rend;//Adds the time to the average
		int waitTime = 0; //How much time should the loop wait in order to maintain constant fps
		Uint32 finTicks = SDL_GetTicks(); //The time it took to render current frame.
		if (finTicks-startTicks < (1000 / TARGET_FPS)) { //The frame was rendered too fast
			waitTime = (1000 / TARGET_FPS) - finTicks+startTicks; 
		}
		SDL_Delay(waitTime);
		running = c < 1000; //For testing only
	}
	printTimes(c);
	int i;
	std::cin >> i;
}

//Testing only
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

//Handles sdl events
void Engine::onEvent(SDL_Event* Event) {
	if (Event->type == SDL_QUIT)
		running = false;
}

//Adds an object to the game
void Engine::addObject(GameObject& obj) {
	SDL_LockMutex(lock); //Acquires the lock to access the game objects vector
	GameObject* addObj = obj.clone();
	gameObjects.push_back(addObj);
	SDL_UnlockMutex(lock); //Releases the lock
}

//Call back function to be called each timer cycle
Uint32 Engine::timerCallBack(Uint32 interval, void *param) {
	Engine* eng = static_cast<Engine*>(param); //Casts the parameter to type Engine
	if (eng->running) {
		eng->moveObj(); //Moves all the objects in the game
	}
	eng->timerId = SDL_AddTimer(TIMER_CYCLE, Engine::timerCallBack, eng); //Recreates the timer with this callback
	return 0;
}

//Moves all the objects in the game
void Engine::moveObj() {
	SDL_LockMutex(lock); //Acquires the lock to access the game objects vector
	for (unsigned int i = 0; i < gameObjects.size(); i = i + 1) { 
		Uint32 mov = SDL_GetTicks(); //Calculates how much time it takes to move this object
		GameObject& curr = *(gameObjects[i]);
		curr.move();
		mov = SDL_GetTicks() - mov; 
		move = move + mov; //Adds the time it took to calculate the average
	}
	SDL_UnlockMutex(lock); //Releases the lock
}

//Draws the game
void Engine::runGame() {
	SDL_LockMutex(lock); //Acquires the lock to access the game objects vector
	for (unsigned int i = 0; i < gameObjects.size(); i = i + 1) {
		GameObject& curr = *(gameObjects[i]);
		Uint32 dra = SDL_GetTicks(); //Time calculation
		curr.draw(graphics);
		dra = SDL_GetTicks() - dra;
		drawRun = drawRun + dra; //Adds the time calculated to the average
	}
	SDL_UnlockMutex(lock); //Releases the lock
}

//Destructor for this engine
Engine::~Engine() {
	SDL_LockMutex(lock);
	for (unsigned int i = 0; i < gameObjects.size(); i = i + 1) {
		delete(gameObjects[i]);
	}
	SDL_UnlockMutex(lock);
	SDL_DestroyMutex(lock);
}