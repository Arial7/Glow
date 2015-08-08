#pragma once

#define GL3_PROTOTYPES 1
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <FTGL/ftgl.h>
#include <iostream>

#include "gameobject.h"
#include "vec3.h"
#include "shader.h"

namespace Glow {

class Renderer{
    public:
        Renderer();
        void init();
        void renderText(const char *_text, float _x, float _y);
        void renderAll();
        void prepare();
        void renderVAO(GLuint vaoID, GLuint vboID);
    private:
        FTPixmapFont *font;
        Shader mainShader;

};

}

