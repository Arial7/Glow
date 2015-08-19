#pragma once

#include "../maths/vec3.h"
#include "renderer2d.h"

namespace Glow {

    class Renderable2D {
        private:
            Vec3 position_;
            Vec2 size_;
            Renderer2D* renderer_;            
        public:
            Renderable2D(Vec3 position, Vec2 size, Renderer* renderer) :
                position_(position), size_(size), renderer_(renderer) {};

            void render(){renderer->submit(this);};

            void setPosition(Vec3 position){position_ = position;};
            void setSize(Vec2 size){size_ = size;};
            void setRenderer(Renderer* renderer){renderer_ = renderer;};

            Vec3 getPosition(){return position_;};
            Vec2 getSize(){return size_;};
            
    };

}
