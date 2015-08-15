#include "glow.h"

#include "time.h"

namespace Glow {

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

    void Engine::enterLoop(){

        while (!quit) {
            Time::update();
            pollEvents();
            update();
            displayManager->swapWindow();
        }

        terminateEngine();
    }

    void Engine::pollEvents(){
        //TODO: better event handling (callbacks?)
        SDL_Event event;
        while (SDL_PollEvent (&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_WINDOWEVENT:
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_RESIZED:
                                displayManager->window_resized(
                                        (int)event.window.data1,
                                        (int)event.window.data2);
                                break;
                    }
                    break;
            }
        }
    }

    void Engine::update() {
    }

    void Engine::terminateEngine(){
        displayManager->destroyWindow();
        SDL_Quit();

        //delete objects
        delete displayManager;
        delete eventQueue;
    }
    

}


