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
            LOG(FATAL) << "Could not create window";
            abort();
        }

        glfwMakeContextCurrent(window_);
        glfwSetWindowUserPointer(window_, this);

        LOG(INFO) << "Window created";

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

    GLFWwindow* Window::getGLFWWindow() {
        return window_;
    }

}}
