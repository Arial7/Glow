#include "application.h"

INITIALIZE_EASYLOGGINGPP


namespace glow {
    void Application::Start() {
        engine = new Engine("Glow - v0.0.1", 1280, 720);
    }

    void Application::End() {
        delete engine;
    }

}
