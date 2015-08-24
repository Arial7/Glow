#pragma once

#include "presets.h"
#include "eventqueue.h"

#include "graphics/displaymanager.h"
#include "graphics/renderer2d.h"

#include "utils/time.h"

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
