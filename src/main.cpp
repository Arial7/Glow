#include "glow.h"
#include "vec3.h"
#include "time.h"

#include <GL/glew.h>

using namespace Glow;

float vertices[] = {
    -1.0, -1.0, 0.0,
     0.0,  1.0, 0.0,
     1.0, -1.0, 0.0
};


GLuint vaoID;
GLuint vboID;
void gameloop();

Engine *glow;


int main(int argc, char *argv[]){
    glow = new Engine();
    glow->initEngine();
 
//TODO: TEMP
    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);


    while(!glow->quit)
        gameloop();
    //if the gameloop exited, cleanup
    glow->terminateEngine();
    delete glow;

    return 0;
}


void gameloop(){
    Time::update();
    glow->pollEvents();
    glow->update();
    //TEMP
    glow->displayManager->swapWindow();
}
