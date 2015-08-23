#pragma once

#include "renderable.h"

namespace Glow {

class Renderer2D{
    public:
        Renderer2D(){};
        virtual ~Renderer2D(){};
        virtual void init(){};
        virtual void submit(Renderable* renderable) = 0;
        virtual void flush() = 0;
};

}

