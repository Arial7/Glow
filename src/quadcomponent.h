#pragma once

#include "component.h"
#include "vec3.h"
#include <GL/glew.h>

namespace Glow {
    
    class QuadComponent : public Component {
        private:
            Vec3 dimensions_;
        public:
            QuadComponent(int entityID, Vec3 dimensions) : Component(entityID),
                dimensions_(dimensions) {};
            
            Vec3 getDimensions() {return dimensions_;};
            void setDimensions(Vec3 dimensions) {dimensions_ = dimensions;};
    };
}