#include "shader.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "log.h"

namespace Glow {

Shader::Shader(const char *vertexFile, const char *fragmentFile){
    GLuint vertexShader, fragmentShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    
    const char *vertexSource = loadFile(vertexFile);
    const char *fragmentSource = loadFile(fragmentFile);

    glShaderSourceARB(vertexShader, 1, &vertexSource, NULL);

    //compile and check the vertex shader
    glCompileShader(vertexShader);
    
    GLint result = GL_FALSE;
    int logLength;

    // Check vertex shader
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<GLchar> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertexShader, logLength, NULL, &vertShaderError[0]);
    
    if((std::string(&vertShaderError[0])).c_str() != "")
//        log(LogLevel::ERROR, "error while compiling vertex shader: "
//                + (std::string(&vertShaderError[0])).c_str()));

    
   

    glShaderSourceARB(fragmentShader, 1, &fragmentSource, NULL);
    //compile and check fragment shader
    glCompileShader(fragmentShader);
    //TODO: implement error checking (and logging)
    
    //create and link the program
    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);

    glLinkProgram(id);
    //TODO: implement error checking (and logging)
    
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

const char *Shader::loadFile(const char *path){
    std::cout << "loading shader " << path << std::endl;
    std::ifstream file(path);
    std::string line;
    std::string content;
    if(file.is_open()){
        while(std::getline(file, line)){
            content += (line + "\n");
        }
        file.close();
    }
    else {
        //TODO: implement logging : unable to open file
    }
    return content.c_str();
}

void Shader::bind(){
    glUseProgram(id);
}

void Shader::unbind(){
    glUseProgram(0);
}

}
