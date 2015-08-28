#pragma once

#include <vector>

#include "interval.h"
#include "timeout.h"

namespace Glow { namespace utils {

class Time {
	public:
		static void init();
		static long deltaTime();
		static float deltaTimeSecs();
		static void update();

		static void addTimeout(long delay, void (*callback)());
		static int addInterval(long delay, void (*callback)());
		static void removeInterval(int id);
	private:
		static std::vector<Timeout> timeouts_;
		static std::vector<Interval> intervals_;
		static int intervalCount;
};

}}
