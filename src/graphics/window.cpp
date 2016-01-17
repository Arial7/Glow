#include "window.h"

#include <iostream>

#include "../utils/log.h"

namespace glow { namespace graphics {

    Window::Window(std::string title, int width, int height) {
        title_ = title;
        width_ = width;
        height_ = height;

        window_ = glfwCreateWindow(width_, height_, title_.c_str(), NULL, NULL);
        if (!window_) {
            // utils::Log(utils::Level::FATAL, "Could not create Window");
            return;
        }

        glfwMakeContextCurrent(window_);
        glfwSetWindowUserPointer(window_, this);

        utils::Log(utils::Level::INFO, "Window created");


    }

    Window::~Window() {
        glfwDestroyWindow(window_);
    }

    void Window::SwapBuffers() {
        glfwSwapBuffers(window_);
    }

    bool Window::ShouldClose() {
        return glfwWindowShouldClose(window_);
    }

}}
