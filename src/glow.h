#pragma once

#include "presets.h"
#include "eventqueue.h"

#include "graphics/displaymanager.h"

#include "utils/time.h"

namespace Glow {

    class Engine {
    private:
        bool quit = false;
    public:
        graphics::DisplayManager *displayManager;
        EventQueue *eventQueue;
    public:
        Engine();
        void initEngine();
        void terminateEngine();
        bool shouldQuit() const;
        void update();
    private:
        void pollEvents();


    };
}
