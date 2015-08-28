#include "time.h"
#include <SDL2/SDL.h>
#include <iostream>

#include "timeout.h"

namespace Glow { namespace utils {

static long lastTime = 0;
static long currentTime = 0;
static long delta = 0;

std::vector<Timeout> Time::timeouts_;

void Time::init() {
	lastTime = SDL_GetTicks();
	currentTime = SDL_GetTicks();
	delta = 0;
}

void Time::update() {
	currentTime = SDL_GetTicks();
	delta = currentTime - lastTime;
	lastTime = currentTime;

    for (unsigned int i = 0; i < timeouts_.size(); i++){
        Timeout& timeout = timeouts_.at(i);
        timeout.delay_ -= delta;
        if(timeout.delay_ <= 0){
            timeout.callback_();
            timeouts_.erase(timeouts_.begin() + i);
        }
    }
    
}

long Time::deltaTime() {
	return delta;
}

float Time::deltaTimeSecs() {
	return delta / 1000.0f;
}

void Time::addTimeout(long delay, void (*callback)()){
    timeouts_.emplace_back(Timeout(delay, callback));
}


}}
