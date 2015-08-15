#include "shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "log.h"

namespace Glow {

//TODO: cleanup

Shader::Shader(const char *vertexFile, const char *fragmentFile){
    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
 
    std::string *vertexString = loadFile(vertexFile);
    std::string *fragmentString = loadFile(fragmentFile);

    const char *vertexSource = vertexString->c_str();
    const char *fragmentSource = fragmentString->c_str();

    glShaderSourceARB(vertexShader, 1, &vertexSource, NULL);
    glShaderSourceARB(fragmentShader, 1, &fragmentSource, NULL);

    delete vertexString;
    delete fragmentString;

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
        log(LogLevel::ERROR, message, "Shader");
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
        log(LogLevel::ERROR, message, "Shader");

    }
    
    //create and link the program
    id = glCreateProgram();

    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);

    glLinkProgram(id);
    //check for errors
    glGetProgramiv(id, GL_LINK_STATUS, &result);
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<GLchar> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(id, logLength, NULL, &programError[0]);
    std::string programErrorString(&programError[0]);
    if(programErrorString.compare("") != 0) {
        std::string message = std::string("error while linking program: ") + programErrorString;
        log(LogLevel::ERROR, message, "Shader");
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
        log(LogLevel::WARN, msg, "Shader");
    }
    return content;
}

void Shader::bind(){
    glUseProgram(id);
}

void Shader::unbind(){
    glUseProgram(0);
}

}
