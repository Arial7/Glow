#include "displaymanager.h"
#include <string>
#include <iostream>

#include "../presets.h"
#include "../utils/log.h"


namespace Glow { namespace graphics {

    using namespace utils;

    DisplayManager::~DisplayManager(){
        destroyWindow();
    }

    void DisplayManager::createWindow(int width, int height, std::string title){
        width_ = width;
        height_ = height;
        gLogger.log(Loglevel::INFO, "creating new window", "DisplayManager");
        initSDL(title);
        initGL();
    }

    void DisplayManager::initSDL(std::string title){
        gLogger.log(Loglevel::INFO, "initializing SDL", "DisplayManager");
        //TODO: Maybe move this call to somewhere else, as later on, audio and
        //networking have to be initialized as well.

        SDL_Init(SDL_INIT_VIDEO);

        //TODO:SDL_WINDOW_RESIZABLE -> implement callback

        //create the window and check if the creation failed
        window_ = SDL_CreateWindow(title.c_str(), 0, 0, width_, height_, SDL_WINDOW_OPENGL |
                SDL_WINDOW_SHOWN);
        if (window_ == NULL) {
            gLogger.log(Loglevel::FATAL, "could not create window",
                    "DisplayManager");
            destroyWindow();
        }
    }

    void DisplayManager::initGL(){
        gLogger.log(Loglevel::INFO, "initializing OpenGL", "DisplayManager");
        //Set OpenGL flags
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, GLOW_WINDOW_DOUBLEBUFFER);
        //create the OpenGL context and check if creation failed
        context_ = SDL_GL_CreateContext(window_);
        if (context_ == NULL) {
            gLogger.log(Loglevel::FATAL, "could not create GL context",
                    "DisplayManager");
            destroyWindow();
        }
        //initialize GLEW
        GLenum glewErr = glewInit();
        if (glewErr != GLEW_OK){
            gLogger.log(Loglevel::FATAL, "could not initialize GLEW");
        }

        //TODO: implement extension checking for better realiablilty
        //TODO: implement alternative rendering for OpenGL 2 and GLES
        //get version string, check if version >= 3.0
        std::string glversion = (const char*)glGetString(GL_VERSION);
        if ((glversion.substr(0, 1).compare("3") != 0) &&
               glversion.substr(0, 1).compare("4") != 0) {
            gLogger.log(Loglevel::FATAL, "OpenGL 3 is not supported");
            gLogger.log(Loglevel::INFO, "GL_MAJOR=" + glversion.substr(0,1));
            abort();
        }
        else {
            gLogger.log(Loglevel::INFO, "OpenGL Version: " + glversion,
                    "DisplayManager");
        }
        glClearColor(0.0, 0.0, 0.0, 1.0);

        //TODO: maybe swap to (0, height, width, 0);
        glViewport(0, 0, width_, height_);
        glOrtho(0, width_ / 2, height_ / 2, 0, -1, 1);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glDisable(GL_DEPTH_TEST);
        glDisable(GL_LIGHTING);

        SDL_GL_SetSwapInterval(GLOW_WINDOW_VSYNC);

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

    void DisplayManager::setWindowTitle(std::string title) {
        SDL_SetWindowTitle(window_, title.c_str());
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

}}
