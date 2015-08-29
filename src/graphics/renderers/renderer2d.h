#pragma once

#include "../renderable2d.h"

namespace Glow { namespace graphics {

class Renderer2D {
    public:
        Renderer2D(){};
        virtual ~Renderer2D(){};
        virtual void init(){};
        virtual void flush() = 0;
        virtual void submit(Renderable2D* renderable){};
};

}}
