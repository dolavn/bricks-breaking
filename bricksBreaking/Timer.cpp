#include "stdafx.h"
#include "Timer.h"
#include <SDL.h>

Timer::Timer(int inverval,void(*func)()):interval(interval),func(func) {

}
