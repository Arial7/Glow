#pragma once

#include <GL/glew.h>
#include <string>

namespace Glow { namespace utils {

class Loader {
	public:
		static GLuint loadTexture(std::string name);
		static void deleteTexture(GLuint tex);
	private:
		static std::string imgPath;
};

}}
