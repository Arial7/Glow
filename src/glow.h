/* -*- C++ -*- */

#pragma once

#include <string>


#include "graphics/window.h"

namespace glow {

    class Engine {
    private:
        graphics::Window* window_;
        void Loop();
    public:
        Engine(std::string windowTitle, int width, int height);
        ~Engine();
    };

}
