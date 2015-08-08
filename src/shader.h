#pragma once

#include <GL/glew.h>

namespace Glow {

class Shader {
    public:
        Shader(){};
        Shader(const char *vertexFile, const char *fragmentFile);
        ~Shader();
        void bind();
        void unbind();
        void bindAttribute(int attribute, const char *variableName);
    private:
        GLuint id;
        const char *loadFile(const char *path);

};

}
