#include "renderer.h"
#include <iostream>

namespace Glow {

Renderer::Renderer() {
    //TODO: load the font when a loadup function is called
	//load the font
	/*
    std::string fontPath("res/VCR_OSD_MONO.ttf");
    font = new FTPixmapFont(fontPath.c_str());
	if(font->Error())
        //TODO: implement logging
		std::cerr << "[RENDERER][WARN]Could not load font " 
            << fontPath << std::endl;
	font->FaceSize(20);
*/
}

Renderer::~Renderer(){
    delete mainShader;
}

void Renderer::init(){
    mainShader = new Shader("./res/shaders/default.vert",
            "./res/shaders/default.frag");
    mainShader->bindAttribute(0, "position");
}

void Renderer::renderText(const char *_text, float _x, float _y){
	int length = strlen(_text);
	FTPoint position(_x, _y - (font->FaceSize() / 2));
	font->Render(_text, length, position, FTPoint(0,0), FTGL::RENDER_ALL);
}

void Renderer::renderAll(){
    //prepare();
}

void Renderer::renderVAO(GLuint vaoID, GLuint vboID){
    //bind everything for rendering
    mainShader->bind();
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);

    //draw
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    //disable attrib arrays and unbind buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);
    mainShader->unbind();
}


void Renderer::prepare() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


}
