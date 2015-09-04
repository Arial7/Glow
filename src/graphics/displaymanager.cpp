#include "displaymanager.h"
#include <iostream>

#include "../eventqueue.h"
#include "../presets.h"

#include "../utils/log.h"


namespace Glow { namespace graphics {

    using namespace utils;

    void framebuffer_resized(GLFWwindow* window, int width, int height);


    DisplayManager::~DisplayManager(){
        destroyWindow();
    }

    void DisplayManager::createWindow(int width, int height, std::string title){
        width_ = width;
        height_ = height;
        title_ = title;
        gLogger.log(Loglevel::INFO, "creating new window", "DisplayManager");
        initGLFW();
        initGL();
    }

    void DisplayManager::initGLFW(){
        gLogger.log(Loglevel::INFO, "initializing GLFW", "DisplayManager");
        if(!glfwInit()){
            gLogger.log(Loglevel::FATAL, "could not initialize GLFW", "DisplayManager");
        }

        //create the window and check if the creation failed
        window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL );
        if (!window_) {
            gLogger.log(Loglevel::FATAL, "could not create window",
                    "DisplayManager");
            destroyWindow();
        }

        glfwMakeContextCurrent(window_);
        glfwSwapInterval(GLOW_WINDOW_VSYNC);
        glfwSetWindowUserPointer(window_, this);
        glfwSetFramebufferSizeCallback(window_, framebuffer_resized);
    }

    void DisplayManager::initGL(){
        gLogger.log(Loglevel::INFO, "initializing OpenGL", "DisplayManager");

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
            gLogger.log(Loglevel::FATAL, "OpenGL 3 or greater is not supported on this system, version is: " + glversion.substr(0, 1), "DisplayManager");
        }
        else {
            gLogger.log(Loglevel::INFO, "OpenGL Version: " + glversion,
                    "DisplayManager");
        }
        glClearColor(0.0, 0.0, 0.0, 1.0);

        //TODO: maybe swap to (0, height, width, 0);
        glViewport(0, 0, width_, height_);
        float widthf = (float) width_;
        float heightf = (float) height_;
        //Set the glOrtho according to the aspect ratio
        glOrtho(0, 100.0 * (widthf / heightf), 100.0 * (widthf / heightf), 0, -1, 1);


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
        glfwSwapBuffers(window_);
    }

    void DisplayManager::destroyWindow(){
        glfwTerminate();
    }



    //callbacks
    void framebuffer_resized(GLFWwindow* window, int width, int height){
        DisplayManager* dm = (DisplayManager*)glfwGetWindowUserPointer(window);

        glViewport(0, 0, width, height);
        dm->height_ = height;
        dm->width_ = width;
    }
    //this is just a wrapper for the method stored in window_focus_handler, because GLFW wants a function with an int as the fucused state, but using a bool is more logical
    void window_focused(GLFWwindow* window, int focused){
        DisplayManager* dm = (DisplayManager*)glfwGetWindowUserPointer(window);
        dm->window_focus_handler((bool)focused);
    }

    //GETTERS & SETTERS
    GLFWwindow* DisplayManager::getWindow() const {
        return window_;
    }

    bool DisplayManager::windowShouldClose(){
        return glfwWindowShouldClose(window_);
    }

    void DisplayManager::setWindowShouldClose(bool close){
        glfwSetWindowShouldClose(window_, close);
    }

    void DisplayManager::setWindowTitle(std::string title) {
        title_ = title;
        glfwSetWindowTitle(window_, title_.c_str());
    }

    void DisplayManager::setWindowSize(int width, int height){
        width_ = width;
        height_ = height;

        glfwSetWindowSize(window_, width_, height_);
    }

    void DisplayManager::setWindowFocusHandler(void (*handler)(bool focused)){
        window_focus_handler = handler;
        glfwSetWindowFocusCallback(window_, window_focused);
    }

}}
