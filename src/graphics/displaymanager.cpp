#include "displaymanager.h"
#include "log.h"
#include <string>
#include <iostream>

namespace Glow {

DisplayManager::~DisplayManager(){
    destroyWindow();
}

void DisplayManager::createWindow(int width, int height, const char *title){
    width_ = width;
    height_ = height;
    log(LogLevel::INFO, "creating new window", "DisplayManager");
    initSDL(title);
    initGL();
}

void DisplayManager::initSDL(const char *title){
    log(LogLevel::INFO, "initializing SDL", "DisplayManager");
    //TODO: Maybe move this call to somewhere else, as later on, audio and
    //networking have to be initialized as well.

    SDL_Init(SDL_INIT_VIDEO);
    
    //create the window and check if the creation failed
    window_ = SDL_CreateWindow(title, 0, 0, width_, height_, SDL_WINDOW_OPENGL |
            SDL_WINDOW_SHOWN);
    if (window_ == NULL) {
        log(LogLevel::FATAL, "could not create window, aborting",
                "DisplayManager");
        destroyWindow();
        abort();
    }
} 

void DisplayManager::initGL(){
    log(LogLevel::INFO, "initializing OpenGL", "DisplayManager");
    //Set OpenGL flags
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    //create the OpenGL context and check if creation failed
    context_ = SDL_GL_CreateContext(window_);
    if (context_ == NULL) {
        log(LogLevel::FATAL, "could not create GL context, aborting",
                "DisplayManager");
        destroyWindow();
        abort();
    }
    //initialize GLEW
    GLenum glewErr = glewInit();
    if (glewErr != GLEW_OK){
        log(LogLevel::FATAL, "could not initialize GLEW");
        abort();
    }
    
    //TODO: implement extension checking for better realiablilty
    //TODO: implement alternative rendering for OpenGL 2 and GLES
    //get version string, check if version >= 3.0
    std::string glversion = (const char*)glGetString(GL_VERSION);
    if ((glversion.substr(0, 1).compare("3") != 0) &&
           glversion.substr(0, 1).compare("4") != 0) {
        log(LogLevel::FATAL, "OpenGL 3 is not supported");
        log(LogLevel::INFO, "GL_MAJOR=" + glversion.substr(0,1));
        abort();
    }
    else {
        log(LogLevel::INFO, "OpenGL Version: " + glversion, 
                "DisplayManager");
    }
    glClearColor(0.0, 0.0, 0.0, 1.0);

    //TODO: maybe swap to (0, height, width, 0);
    glViewport(0, 0, width_, height_);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    //TODO: check for errors

}

void DisplayManager::clearWindow() const {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DisplayManager::swapWindow() const {
    SDL_GL_SwapWindow(window_);
}

void DisplayManager::destroyWindow(){
    //only clean up the objects if they got created

    if(window_ != NULL)  SDL_GL_DeleteContext(context_); 
    if(context_ != NULL) SDL_DestroyWindow(window_); 
    //TODO:check for other things to cleanup 
}

void DisplayManager::window_resized(int width, int height){
    width_ = width;
    height_ = height;
    glViewport(0, 0, width_, height_);
}


//GETTERS & SETTERS
SDL_Window *DisplayManager::getWindow(){
    return window_;
}

}
