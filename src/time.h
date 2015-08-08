#pragma once

namespace Glow {

class Time {
	public:
		static void init();
		static long deltaTime();
		static float deltaTimeSecs();
		static void update();		
};

}
