#pragma once

#include <GL/glew.h>
#include "vec3.h"
#include "component.h"

namespace Glow {

class GameObject {
    private:
        Component *input_;
        Component *physics_;
        Component *graphics_;
	protected:
		Vec3 position_;
    public:
		GameObject(Component *input, Component *physics, Component *graphics);
        ~GameObject();
        void update();
        void setInputComponent(Component *component);
        void setPhysicsComponent(Component *component);
        void setGraphicsComponent(Component *component);



};

}

