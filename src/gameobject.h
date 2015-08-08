#pragma once

#include <GL/glew.h>
#include "vec3.h"
#include "component.h"

namespace Glow {

class GameObject {
	public:
		GameObject();
	protected:
		Vec3 position_;

};

}

