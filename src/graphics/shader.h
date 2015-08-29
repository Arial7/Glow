#pragma once

#include <GL/glew.h>
#include <string>

namespace Glow { namespace graphics {

class Shader {
    public:
        Shader(){};
        Shader(const char *vertexFile, const char *fragmentFile);
        ~Shader();
        void bind();
        void unbind();
        void bindAttribute(int attribute, const char *variableName);
        GLuint getUniformLocation(std::string uniformName);

    private:
        GLuint id;
        std::string *loadFile(const char *path);

};

}}
