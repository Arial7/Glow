#pragma once

    
#define GLOW_DEFAULT_WINDOW_WIDTH   1280
#define GLOW_DEFAULT_WINDOW_HEIGHT  720
#define GLOW_DEFAULT_WINDOW_TITLE   "Glow3D"

#include "displaymanager.h"
#include "entitymanager.h"
#include "renderer.h"


namespace Glow {
    
    DisplayManager *displayManager;
    EntityManager *entityManager;
    Renderer *renderer;

    void initEngine();
    void enterLoop();
    void pollEvents();
    void update();
    void terminateEngine();

}


