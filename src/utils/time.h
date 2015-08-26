#pragma once

namespace Glow { namespace utils {

class Time {
	public:
		static void init();
		static long deltaTime();
		static float deltaTimeSecs();
		static void update();
};

}}
