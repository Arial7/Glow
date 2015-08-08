#include "displaymanager.h"
#include "log.h"
#include <string>

namespace Glow {

void DisplayManager::createWindow(int _width, int _height, const char *_title){
    width = _width;
    height = _height;
    log(LogLevel::INFO, "creating new window", "DisplayManager");
    initSDL(_title);
    initGL();
}

void DisplayManager::initSDL(const char *_title){
    log(LogLevel::INFO, "initializing SDL", "DisplayManager");
    //TODO: Maybe move this call to somewhere else, as later on, audio and
    //networking have to be initialized as well.

    SDL_Init(SDL_INIT_VIDEO);
    
    //create the window and check if the creation failed
    window = SDL_CreateWindow(_title, 0, 0, width, height, SDL_WINDOW_OPENGL |
            SDL_WINDOW_SHOWN);
    if (window == NULL) {
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
    context = SDL_GL_CreateContext(window);
    if (context == NULL) {
        log(LogLevel::FATAL, "could not create GL context, aborting",
                "DisplayManager");
        destroyWindow();
        abort();

    }
    //initialize GLEW
    GLenum glewErr = glewInit();
    if (glewErr != GLEW_OK){
        abort();
    }

    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    //TODO: maybe swap to (0, height, width, 0);
 //   glViewport(0, 0, width, height);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    /* TODO
     *glEnable(GL_DEPTH_TEST);
     *glEnable(GL_LIGHTING);
     */

    //TODO: check for errors

}

void DisplayManager::destroyWindow(){
    //only clean up the objects if they got created

    if(window != NULL)  SDL_GL_DeleteContext(context); 
    if(context != NULL) SDL_DestroyWindow(window); 
    //TODO:check for other things to cleanup 
}

DisplayManager::~DisplayManager(){
    destroyWindow();
}

//GETTERS & SETTERS
SDL_Window *DisplayManager::getWindow(){
    return window;
}

}
