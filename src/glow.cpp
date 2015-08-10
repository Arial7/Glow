#include "glow.h"

#include "time.h"

namespace Glow {

    bool quit = false;

    void initEngine(){
        displayManager = new DisplayManager();
        entityManager = new EntityManager();
        renderer = new Renderer();

        //TODO: make the engine read settings from somewhere
        displayManager->createWindow(GLOW_DEFAULT_WINDOW_WIDTH,
                GLOW_DEFAULT_WINDOW_HEIGHT, 
                GLOW_DEFAULT_WINDOW_TITLE);
        renderer->init();
        Time::init();
    }

    void enterLoop(){

        while (!quit) {
            Time::update();
            pollEvents();
            update();
            displayManager->swapWindow();
        }

        terminateEngine();
    }

    void pollEvents(){
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

    void update() {
        renderer->prepare();
        renderer->renderAll();
    }

    void terminateEngine(){
        displayManager->destroyWindow();
        SDL_Quit();
        //delete objects
        delete displayManager;
        delete entityManager;
        delete renderer;
    }


}


