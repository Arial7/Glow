#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>


#include "displaymanager.h"
#include "renderer.h"
#include "time.h"
#include "log.h"

#include "vec3.h"


//TODO: create settings parser to read these settings from a file
//the size of the window, defaulted to HD, which should be the minimum size of a monitor nowadays
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "Glow3D - Pascal Riesinger"

namespace Glow {

//set to true when the game should exit
bool quit = false;

//important objects, such as the renderer
Renderer renderer;
DisplayManager displayManager;

//TODO: TEMP
const GLfloat vertices[] = {
    -1.0, -1.0, 0.0,
     1.0, -1.0, 0.0,
     0.0,  1.0, 0.0
};

GLuint vboID;
GLuint vaoID;

//function prototypes
void start();
void loadup();
void gameloop();
void update();
void cleanup();

void start() {
    displayManager.createWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    //TODO:create proper resource management system   
    loadup();
    gameloop();
    cleanup();
}

void checkGLError(const char *msg){
    int error = glGetError();
    if (error != 0){
        std::string message = msg; 
        message.append(std::to_string(error));
        log(LogLevel::ERROR, message.c_str());
    }
}


void loadup() {
	renderer.init();
    
    //initialize the timing subsystem
    Time::init();
    
    checkGLError("nothing done yet");

    //TODO: TEMP
    glGenVertexArrays(1, &vaoID);
    checkGLError("created vao");
    
    glBindVertexArray(vaoID);
    glEnableVertexAttribArray(0);
    
    glGenBuffers(1, &vboID);
    glBindBuffer(GL_ARRAY_BUFFER, vboID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    checkGLError("after buffering");

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDisableVertexAttribArray(0);
    glBindVertexArray(0);

}

void gameloop(){
	SDL_Event event;
	while (!quit) {
		//update the delta time
		Time::update();
		//get all SDL_Events and handle them
		while (SDL_PollEvent (&event)) {
			switch (event.type) {
				case SDL_QUIT: //SDL_Quit = close window
					quit = true;
				    break;
			}
		}
		update();
		//swap framebuffers
		SDL_GL_SwapWindow(displayManager.getWindow());
	}
}

void update(){
    //TODO: update the input
    renderer.prepare();
    renderer.renderVAO(vaoID, vboID);
    //after everything is done updating render every element
    renderer.renderAll();
}


void cleanup(){
    displayManager.destroyWindow();
	
	SDL_Quit();
}


}


int main(int argc, char *argv[]){
    Glow::start();
	return 0;
}
