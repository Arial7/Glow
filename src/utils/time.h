#pragma once

#include <vector>
#include "timeout.h"

namespace Glow { namespace utils {

class Time {
	public:
		static void init();
		static long deltaTime();
		static float deltaTimeSecs();
		static void update();

		static void addTimeout(long delay, void (*callback)());
	private:
		static std::vector<Timeout> timeouts_;
};

}}
