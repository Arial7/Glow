#pragma once

#include <GL/glew.h>
#include "loader.h"

namespace Glow {

//TODO: better texture management system

class Textures {
	public:
		static void loadTextures (void);
		static void deleteTextures (void);
		static GLuint icon_health;
		static GLuint icon_play;
		static GLuint icon_pause;

		static GLuint building_mainTower;
		static GLuint character_default;

};

}
