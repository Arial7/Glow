#pragma once

#include "../maths/vec3.h"
#include "../maths/vec2.h"
#include "renderer2d.h"
#include "renderable.h"

namespace Glow { namespace graphics {

    using namespace maths;

    class Renderable2D : public Renderable {
        private:
            vec3 position_;
            vec2 size_;
            Renderer2D* renderer_;
        public:
            Renderable2D(vec3 position, vec2 size, Renderer2D* renderer) :
                position_(position), size_(size), renderer_(renderer) {};

            void render(){renderer_->submit(this);};

            void setPosition(vec3 position){position_ = position;};
            void setSize(vec2 size){size_ = size;};
            void setRenderer(Renderer2D* renderer){renderer_ = renderer;};

            vec3 getPosition(){return position_;};
            vec2 getSize(){return size_;};

    };

}}
