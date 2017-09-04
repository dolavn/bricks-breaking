#pragma once
#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>

class Timer {
public:
	Timer(int interval,void(*func)());
private:
	int interval;
	void(*func)();
};

#endif