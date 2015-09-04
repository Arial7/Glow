#include "glow.h"

#include "utils/log.h"

#include <GLFW/glfw3.h>


namespace Glow {

    using namespace utils;
    using namespace graphics;


    Engine::Engine(){
        eventQueue = new EventQueue();
        displayManager = new DisplayManager();
    }

    void Engine::initEngine(){

        //TODO: make the engine read settings from somewhere
        displayManager->createWindow(GLOW_WINDOW_WIDTH,
                GLOW_WINDOW_HEIGHT,
                GLOW_WINDOW_TITLE);
        Time::init();
    }

    void Engine::pollEvents(){
        //eventQueue->pollEvents();
    }

    void Engine::update() {
        Time::update();
        pollEvents();
    }

    void Engine::terminateEngine(){
        displayManager->destroyWindow();

        //delete objects
        delete displayManager;
        delete eventQueue;
    }

    bool Engine::shouldQuit() const {
        return quit || displayManager->windowShouldClose();

    }

}
