
#include "input.h"

#include "../gl.h"
#include "../utils/log.h"

namespace glow { namespace input {

    int Input::KEY_PRESSED = 1;
    int Input::KEY_RELEASED = 2;
    graphics::Window* Input::window_ =  nullptr;

    void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_E && action == GLFW_PRESS) {
            LOG(INFO) << "E Pressed";
        }
    }

    int Input::getKey(int keycode) {
        int returnCode = glfwGetKey(window_->getGLFWWindow(), keycode );
        if (returnCode == GLFW_PRESS) return KEY_PRESSED;
        else if (returnCode == GLFW_RELEASE) return KEY_RELEASED;
        else {
            LOG(ERROR) << "Something went wrong while calling getKey: returnCode was" + returnCode;
            return 0;
        }
    }

    void Input::init(graphics::Window* window) {
        glfwSetKeyCallback(window->getGLFWWindow(), key_callback);
        window_ = window;
    };


}}
