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

        glShaderSourceARB(vertexShader, 1, &vertexSource, NULL);
        glShaderSourceARB(fragmentShader, 1, &fragmentSource, NULL);

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

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
        glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> fragShaderError((logLength > 1) ? logLength : 1);
        glGetShaderInfoLog(fragmentShader, logLength, NULL, &fragShaderError[0]);
        std::string fragmentErrorString(&fragShaderError[0]);
        if(fragmentErrorString.compare("") != 0){
            std::string message = std::string("error while compiling fragment shader: ")
                + fragmentErrorString;
            gLogger.log(Loglevel::ERROR, message, "Shader");

        }


        //create and link the program
        id = glCreateProgram();

        glAttachShader(id, vertexShader);
        glAttachShader(id, fragmentShader);


        //bind the attributes
        //bindAttribute(SHADER_ATTRIB_POSITION, "position");
        //bindAttribute(SHADER_ATTRIB_COLOR, "color");

        glLinkProgram(id);
        //check for errors
        glGetProgramiv(id, GL_LINK_STATUS, &result);
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
        std::vector<GLchar> programError( (logLength > 1) ? logLength : 1 );
        glGetProgramInfoLog(id, logLength, NULL, &programError[0]);
        std::string programErrorString(&programError[0]);
        if(programErrorString.compare("") != 0) {
            gLogger.log(Loglevel::ERROR, "error while linking program: " + programErrorString, "Shader");
        }

        //clean up the shaders
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

    }

    Shader::~Shader(){
        glDeleteProgram(id);
    }

    void Shader::bindAttribute(int attribute, const char *variableName){
        glBindAttribLocation(id, attribute, variableName);
    }

    std::string *Shader::loadFile(const char *path){
        std::ifstream file(path);
        std::string line;
        std::string *content = new std::string();
        if(file.is_open()){
            while(std::getline(file, line)){
                content->append(line + "\n");
            }
            file.close();
        }
        else {
            std::string msg = "file ";
            msg.append(path);
            msg.append(" could not be opened");
            gLogger.log(Loglevel::WARN, msg, "Shader");
        }
        return content;
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
        for (auto itr = uniformLocations.begin(); itr != uniformLocations.end(); ++itr){
            if (strcmp(itr->first, uniformName) == 0)
                return itr->second;
        }
        uniformLoc = glGetUniformLocation(id, uniformName);
        if (uniformLoc == -1) {
            gLogger.log(Loglevel::FATAL, "Trying to acces non-existant unform", "Shader");
            return NULL;
        }
        std::pair<const GLchar*, GLint> newUniformLocation(uniformName, uniformLoc);
        uniformLocations.insert(newUniformLocation);
        gLogger.log(Loglevel::WARN, "Loading uniformLocation for first time", "Shader");
        return newUniformLocation.second;
    }

    void Shader::bind(){
        glUseProgram(id);
    }

    void Shader::unbind(){
        glUseProgram(0);
    }

}}
