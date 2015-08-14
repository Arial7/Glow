#pragma once

#define GL3_PROTOTYPES 1
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <FTGL/ftgl.h>
#include <iostream>

#include "gameobject.h"
#include "vec3.h"
#include "vec2.h"
#include "shader.h"

namespace Glow {

class Renderer{
    public:
        Renderer();
        virtual ~Renderer(){};
        virtual void init() = 0;
        virtual void submit() = 0;
        virtual void flush() = 0;
};

}

