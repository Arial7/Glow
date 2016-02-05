#include "glow.h"

#include "gl.h"

#include "utils/log.h"



namespace glow {

    Engine::Engine(std::string windowTitle, int width, int height) {
        if (!glfwInit()) {
            LOG(FATAL) << "Could not initialize GLFW";
            abort();
        }
        window_ = new graphics::Window(windowTitle, width, height);

        input::Input::init(window_);

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
            if(input::Input::getKey(GLFW_KEY_ESCAPE) == input::Input::KEY_PRESSED) {
                break;
            }
        }

    }

}
