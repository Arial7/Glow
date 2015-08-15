#pragma once

#include <GL/glew.h>
#include <string>

namespace Glow {

class Loader {
	public:
		static GLuint loadTexture(std::string name);
		static void deleteTexture(GLuint tex);
	private:
		static std::string imgPath;
};

}
