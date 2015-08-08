#pragma once

#include <GL/glew.h>
#include <string>

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
        std::string *loadFile(const char *path);

};

}
