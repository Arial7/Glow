/* -*- C++ -*- */

#pragma once

#include <string>
#include "../gl.h"

namespace glow { namespace graphics {

    class Window {
    private:
        int width_;
        int height_;
        std::string title_;
        GLFWwindow* window_ = nullptr;
    public:
        Window(std::string title, int width, int height);
        ~Window();

        void SwapBuffers();
        bool ShouldClose();
        GLFWwindow* getGLFWWindow();
    };

}}
