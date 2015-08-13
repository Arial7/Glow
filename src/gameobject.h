#pragma once

#include "presets.h"

#include <GL/glew.h>
#include "component.h"

#ifdef GLOW_PRESET_2D
    #include "vec2.h"
#elif defined GLOW_PRESET_3D
    #include "vec3.h"
#endif


namespace Glow {

class GameObject {
    private:
        Component *input_;
        Component *physics_;
        Component *graphics_;
	protected:
#ifdef GLOW_PRESET_2D
        Vec2 position_;
#elif defined GLOW_PRESET_3D
        Vec3 position_;
#endif
    public:
#ifdef GLOW_PRESET_2D
        GameObject(Vec2 position, Component *input, Component *physics, Component *graphics);
#elif defined GLOW_PRESET_3D
        GameObject(Vec3 position, Component *input, Component *physics, Component *graphics);
#endif
        ~GameObject();
        void update();
        void setInputComponent(Component *component);
        void setPhysicsComponent(Component *component);
        void setGraphicsComponent(Component *component);




};

}

