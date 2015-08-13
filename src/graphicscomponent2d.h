#pragma once

#include "component.h"
#include "renderer.h"

namespace Glow {

    class GraphicsComponent2D : public Component {
        protected:
           Renderer *renderer_;
           float width_, height_;
        public:
            GraphicsComponent2D(const Renderer &renderer);
    
    };

}
