#pragma once

#include "component.h"
#include "vec3.h"

namespace Glow {

    class TransformComponent : public Component {
        public:
            TransformComponent(int entityID, Vec3 position) :
                Component(entityID), position_(position), 
                rotation_(Vec3(0,0,0));
            TransformComponent(int entityID, Vec3 position, 
                    Vec3 rotation) :
                Component(entityID), position_(position), rotation_(rotation);
            
            Vec3 getPosition() {return position_;};
            Vec3 getRotation() {return rotation_;};

            void setPosition(Vec3 position) {position_ = position;};
            void setRotation(Vec3 rotation) {rotation_ = rotation;};            
        private:
            Vec3 position_;
            Vec3 rotation_;
    };

}
