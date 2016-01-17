#include "glow.h"

#include <GLFW/glfw3.h>

namespace glow {

    Engine::Engine(std::string windowTitle, int width, int height) {
        glfwInit();
        window_ = new graphics::Window(windowTitle, width, height);

        Loop();

    }

    Engine::~Engine() {
        delete window_;
        glfwTerminate();
    }


    void Engine::Loop() {
        while (!window_->ShouldClose()) {
            window_->SwapBuffers();
            glfwPollEvents();
        }

    }

}
