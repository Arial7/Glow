#include "shader.h"

#include <iostream>
#include <fstream>
#include <iostream>
#include <vector>

#include "../utils/fileutils.h"
#include "../utils/log.h"

namespace Glow { namespace graphics {

    using namespace utils;

    //TODO: cleanup, DRY

    Shader::Shader(const char *vertexFile, const char *fragmentFile){
        GLuint vertexShader, fragmentShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        const char *vertexSource = File(vertexFile).read().c_str();
        const char *fragmentSource = File(fragmentFile).read().c_str();

        glShaderSource(vertexShader, 1, &vertexSource, NULL);
        glShaderSource(fragmentShader, 1, &fragmentSource, NULL);

        //compile and check the vertex shader
        glCompileShader(vertexShader);

        GLint result = GL_FALSE;
        int logLength;

        // Check vertex shader
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> vertShaderError((logLength > 1) ? logLength : 1);
        glGetShaderInfoLog(vertexShader, logLength, NULL, &vertShaderError[0]);
        std::string vertexErrorString(&vertShaderError[0]);
        if(vertexErrorString.compare("") != 0){
            std::string message = std::string("error while compiling vertex shader: ")
                + vertexErrorString;
            gLogger.log(Loglevel::ERROR, message, "Shader");
        }


        //compile and check fragment shader
        glCompileShader(fragmentShader);



        //create and link the program
        id = glCreateProgram();

        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);

        //bind the attributes
        //bindAttribute(SHADER_ATTRIB_POSITION, "position");
        //bindAttribute(SHADER_ATTRIB_COLOR, "color");

        glLinkProgram(id);
        //check for errors


        //clean up the shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

    }

    bool Shader::checkCompileStatus(GLuint id){
        GLint result = GL_FALSE;
        GLint type;
        int logLength;
        glGetShaderiv(id, GL_COMPILE_STATUS, &result);
        if (result == GL_TRUE) {
            return true;
        }
        glGetShaderiv(id, GL_SHADER_TYPE, &type);
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> errorVec((logLength > 1) ? logLength : 1);
        glGetShaderInfoLog(id, logLength, NULL, &errorVec[0]);
        std::string errorString(&errorVec[0]);
        if(errorString.compare("") != 0){
            if (type == GL_VERTEX_SHADER) {
                gLogger.log(Loglevel::ERROR, "error while compiling vertex shader: " +
                errorString, "Shader");
            }
            else if (type == GL_FRAGMENT_SHADER) {
                gLogger.log(Loglevel::ERROR, "error while compiling fragment shader: " +
                errorString, "Shader");
            }
            else {
                //TODO: add ability to use geometry and tesselation shaders
                gLogger.log(Loglevel::ERROR, "unknown error while compiling shader: " +
                errorString, "Shader");
            }

        }
        return false;
    }
    bool Shader::checkLinkStatus(GLuint id){
        GLint result = GL_FALSE;
        int logLength;
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        if (result == GL_TRUE) {
            return true;
        }
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> errorVec( (logLength > 1) ? logLength : 1 );
        glGetProgramInfoLog(id, logLength, NULL, &errorVec[0]);
        std::string errorString(&errorVec[0]);
        if(errorString.compare("") != 0) {
            gLogger.log(Loglevel::ERROR, "error while linking program: " +
                errorString, "Shader");
        }
        return false;
    }



    Shader::~Shader(){
        glDeleteProgram(id);
    }

    void Shader::bindAttribute(int attribute, const char *variableName){
        glBindAttribLocation(id, attribute, variableName);
    }

    void Shader::setUniform1i(const GLchar* name, int value){
        glUniform1i(getUniformLocation(name), value);
    }

    void Shader::setUniform1f(const GLchar* name, float value){
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setUniform2f(const GLchar* name, const vec2& value){
        glUniform2f(getUniformLocation(name), value.x, value.y);
    }

    void Shader::setUniform3f(const GLchar* name, const vec3& value){
        glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
    }

    void Shader::setUniform4f(const GLchar* name, const vec4& value){
        glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
    }

    void Shader::setUniformMat4(const GLchar* name, const mat4& value){
        glUniformMatrix4fv(getUniformLocation(name),  1, GL_FALSE, value.elements);
    }

    GLint Shader::getUniformLocation(const GLchar* uniformName){
        //Try to get the uniform location from the cache, as it is
        //expensive to get them from GL
        for (auto itr = uniformLocations.begin(); itr != uniformLocations.end(); ++itr){
            if (strcmp(itr->first, uniformName) == 0)
                return itr->second;
        }
        GLint uniformLoc = glGetUniformLocation(id, uniformName);
        if (uniformLoc == -1) {
            gLogger.log(Loglevel::FATAL,
                "Trying to acces non-existant uniform, check your shaders!", "Shader");
            return -1;
        }
        std::pair<const GLchar*, GLint> newUniformLocation(uniformName, uniformLoc);
        uniformLocations.insert(newUniformLocation);
        //TODO: this is only for debugging and should be removed
        gLogger.log(Loglevel::INFO, "Loading uniformLocation of: " + std::string(uniformName) + " for first time", "Shader");
        return newUniformLocation.second;
    }

    void Shader::bind(){
        glUseProgram(id);
    }

    void Shader::unbind(){
        glUseProgram(0);
    }

}}
