#pragma once

#include <vector>

#include "interval.h"
#include "timeout.h"

namespace Glow { namespace utils {

class Time {
	public:
		static void init();

		static double deltaTime();
		static double deltaTimeSecs();
		static void update();

		static void addTimeout(double delay, void (*callback)());
		static int addInterval(double delay, void (*callback)());
		static void removeInterval(int id);
	private:
		static double lastTime;
		static double currentTime;
		static double delta;

		static std::vector<Timeout> timeouts_;
		static std::vector<Interval> intervals_;
		static int intervalCount;
};

}}
