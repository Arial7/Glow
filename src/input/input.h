/* -*- C++ -*- */

#pragma once

#include "../graphics/window.h"

namespace glow { namespace input {

    class Input {
    public:
        static int KEY_PRESSED;
        static int KEY_RELEASED;

        static void init(graphics::Window* window);
        static int getKey(int keycode);
    private:
        static void key_callback(GLFWwindow*, int, int, int, int);
        static graphics::Window* window_;
    };

}}
