#include "glow.h"

//TODO: TEMP
/*    glGenVertexArrays(1, &vaoID);
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
*/



int main(int argc, char *argv[]){
    Glow::initEngine();
    Glow::enterLoop();
	return 0;
}
