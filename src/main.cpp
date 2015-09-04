#include <GL/glew.h>

#include <iostream>
#include <string>

#include "glow.h"

#include "graphics/renderable2d.h"
#include "graphics/shader.h"

#include "graphics/buffers/vertexarray.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexbuffer.h"

#include "graphics/renderers/renderer2d.h"
#include "graphics/renderers/simplerenderer2d.h"

#include "maths/maths.h"

#include "utils/time.h"
#include "utils/log.h"


//PLEASE NOTE:
//This class is only used for testing. Everything in this class should be implemented by the
//game iteself. This class is not a part of the engine


using namespace Glow;
using namespace graphics;


Engine *glow;

Renderer2D* renderer;
Shader* shader;

//FPS measureing
int fps;
int fpsCounterInterval;

void print_fps(){
    glow->displayManager->setWindowTitle("Glow 3D - FPS: " + std::to_string(fps));
    fps = 0;
}

void exitEngine(){
    glow->displayManager->setWindowShouldClose(true);
    utils::gLogger.log(utils::Loglevel::WARN, "setting windowShouldClose to true");
}

int main(int argc, char *argv[]){
    utils::gLogger.log(utils::Loglevel::INFO, "starting..");

    glow = new Engine();
    glow->initEngine();

    utils::gLogger.log(utils::Loglevel::INFO, "engine initialized");

    renderer = new SimpleRenderer2D();
    shader = new Shader("res/shaders/default.vert", "res/shaders/default.frag");

    Renderable2D renderable(maths::vec3(0, 0, 0), maths::vec2(20, 20), shader);

    fpsCounterInterval = utils::Time::addInterval(1000, &print_fps);
    utils::Time::addTimeout(1000, &exitEngine);

    while(!glow->shouldQuit()){
        glow->update();

        glow->displayManager->clearWindow();

        glColor3f(1, 1, 1);

        //TEMP
        renderer->submit(&renderable);

        renderer->flush();

        //after everything has been rendered, swap the framebuffers
        glow->displayManager->swapWindow();

        fps++;
    }


    //if the gameloop exited, cleanup
    glow->terminateEngine();

    //cleanup
    delete glow;

    delete renderer;
    delete shader;

    return 0;
}
