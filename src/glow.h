#pragma once

#include "presets.h"

#include "displaymanager.h"
#include "entitymanager.h"
#include "renderer.h"


namespace Glow {
    
    struct Engine {
        Engine();

        bool quit = false;

        DisplayManager *displayManager;
        EntityManager *entityManager;
        Renderer *renderer;


        void initEngine();
        void enterLoop();
        void pollEvents();
        void update();
        void terminateEngine();
    };
}


