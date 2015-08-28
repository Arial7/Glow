#include "time.h"

#include <iostream>
#include <SDL2/SDL.h>


namespace Glow { namespace utils {

static long lastTime = 0;
static long currentTime = 0;
static long delta = 0;

std::vector<Timeout> Time::timeouts_;
std::vector<Interval> Time::intervals_;

int Time::intervalCount = 0;

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

	for (unsigned int i = 0; i < intervals_.size(); i++) {
		Interval& interval = intervals_.at(i);
		interval.delay_ -= delta;
		if(interval.delay_ <= 0){
			interval.callback_();
			interval.delay_ = interval.interval_;
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

int Time::addInterval(long delay, void (*callback)()){
	intervalCount++;
	intervals_.emplace_back(Interval(delay, callback, intervalCount));
	return intervalCount;
}

void Time::removeInterval(int id){
	for (unsigned int i = 0; i < intervals_.size(); i++){
		if (intervals_.at(i).id_ == id)
			intervals_.erase(intervals_.begin() + i);
	}
}

}}
