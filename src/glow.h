#pragma once

#include "presets.h"

#include "displaymanager.h"
#include "renderer.h"
#include "eventqueue.h"

namespace Glow {
    
    struct Engine {
        Engine();

        bool quit = false;

        DisplayManager *displayManager;
        EventQueue *eventQueue;

        void initEngine();
        void enterLoop();
        void pollEvents();
        void update();
        void terminateEngine();
    };
}


