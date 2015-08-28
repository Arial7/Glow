#include <GL/glew.h>

#include <iostream>
#include <string>

#include "glow.h"

#include "graphics/shader.h"

#include "graphics/buffers/vertexarray.h"
#include "graphics/buffers/buffer.h"
#include "graphics/buffers/indexbuffer.h"

#include "maths/vec2.h"

#include "utils/time.h"
#include "utils/log.h"


//PLEASE NOTE:
//This class is only used for testing. Everything in this class should be implemented by the
//game iteself. This class is not a part of the engine


using namespace Glow;
using namespace graphics;

GLfloat vertices[] = {
    -0.5, -0.5, 0,
    -0.5,  0.5, 0,
     0.5,  0.5, 0,
     0.5,  -0.5, 0
};

GLushort indices[] = {
    0, 1, 2,
    2, 3, 0
};


Engine *glow;

//FPS measureing
int fps;
int fpsCounterInterval;

void print_fps(){
    utils::gLogger.log(utils::Loglevel::INFO, "FPS: " + std::to_string(fps));
    fps = 0;
}

int main(int argc, char *argv[]){
    glow = new Engine();
    glow->initEngine();

    utils::gLogger.log(utils::Loglevel::INFO, "engine initialized");

    maths::vec2 a = maths::vec2(1, 4);
    a += maths::vec2(0, 19.5);

    std::cout << a << std::endl;


    Shader shader("res/shaders/default.vert", "res/shaders/default.frag");

    VertexArray* vao = new VertexArray();
    Buffer* vbo = new Buffer(vertices, 12, 3);
    IndexBuffer ibo(indices, 6);

    fpsCounterInterval = utils::Time::addInterval(1000, &print_fps);
    
    vao->addBuffer(vbo, 0);

    while(!glow->quit){
        utils::Time::update();
        glow->pollEvents();
        glow->update();

        glow->displayManager->clearWindow();

        glColor3f(1, 1, 1);
        shader.bind();

        //TEMP
        vao->bind();
        ibo.bind();
        glDrawElements(GL_TRIANGLES, ibo.getCount(), GL_UNSIGNED_SHORT, 0);
        vao->unbind();
        ibo.unbind();

        shader.unbind();

        glow->displayManager->swapWindow();

        fps++;
    }


    //if the gameloop exited, cleanup
    glow->terminateEngine();

    //cleanup
    delete glow;
    delete vao;

    return 0;
}
