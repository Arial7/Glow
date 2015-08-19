#pragma once

#include "renderable2d.h"

namespace Glow {

class Renderer2D{
    public:
        Renderer(){};
        virtual ~Renderer(){};
        virtual void init(){};
        virtual void submit(Renderable2D*  renderable) = 0;
        virtual void flush() = 0;
};

}

