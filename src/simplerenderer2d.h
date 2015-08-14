#pragma once

#include <GL/glew.h>

#include "renderer.h"

class SimpleRenderer2D : public Renderer {
    
    public:
        SimpleRenderer2D();
        ~SimpleRenderer2D();
        
        virtual void init();
        virtual void submit();
        virtual void flush();
}

