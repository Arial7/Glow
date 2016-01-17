/* -*- C++ -*- */

#pragma once

#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
    };

}}
