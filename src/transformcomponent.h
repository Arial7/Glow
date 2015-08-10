#pragma once

#include "component.h"
#include "vec3.h"

namespace Glow {

    class TransformComponent : public Component {
        private:
            Vec3 position_;
            Vec3 rotation_;
        public:
            TransformComponent(Vec3 position) : position_(position), 
                rotation_(0,0,0){};
            TransformComponent(Vec3 position, Vec3 rotation) :
                position_(position), rotation_(rotation){};
            
            Vec3 getPosition() {return position_;};
            Vec3 getRotation() {return rotation_;};

            void setPosition(Vec3 position) {position_ = position;};
            void setRotation(Vec3 rotation) {rotation_ = rotation;};            
    };

}
