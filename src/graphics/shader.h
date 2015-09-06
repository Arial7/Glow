#pragma once

#include <GL/glew.h>
#include <string>
#include <string.h>
#include <map>

#include "../maths/maths.h"


#define SHADER_ATTRIB_POSITION  0
#define SHADER_ATTRIB_UV        1
//#define SHADER_ATTRIB_MASK_UV   2
#define SHADER_ATTRIB_TEXTURE   3
#define SHADER_ATTRIB_COLOR     5

namespace Glow { namespace graphics {

using namespace maths;

    class Shader {
        private:
            GLuint id;
            //this map acts as a cache for uniform locations, as it is very costly to get these.
            std::map<const GLchar*, GLint> uniformLocations;
        public:
            Shader(){};
            Shader(const char *vertexFile, const char *fragmentFile);
            ~Shader();
            void bind();
            void unbind();
            void bindAttribute(int attribute, const char *variableName);

            void setUniform1i(const GLchar* name, int value);
            void setUniform1f(const GLchar* name, float value);
            void setUniform2f(const GLchar* name, const vec2& value);
            void setUniform3f(const GLchar* name, const vec3& value);
            void setUniform4f(const GLchar* name, const vec4& value);
            void setUniformMat4(const GLchar* name, const mat4& value);

        private:
            std::string *loadFile(const char *path);
            GLint getUniformLocation(const GLchar* uniformName);

    };

}}
