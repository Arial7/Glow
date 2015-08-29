#include "loader.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

#include "log.h"

namespace Glow { namespace utils {

//TODO: cleanup

//This is the path of the images location
std::string Loader::imgPath = "res/images/";

GLuint Loader::loadTexture(std::string name) {
	std::string filepath(imgPath + name);
	GLuint texture;

	//Load the image to a SDL_Surface
	SDL_Surface *surface = IMG_Load(filepath.c_str());
	if (surface == nullptr) {
        //TODO: logging
    }
	//generate the GL texture and tweak it a bit
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);

	//Set up scaling behaviour
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);

	//Do some cleanup
	SDL_FreeSurface(surface);

	//Bind the default "NULL" texture again, so no faulty texture rendering might appear
	glBindTexture(GL_TEXTURE_2D, 0);

	//Check if there are any OpenGL errors in the pipeline
	GLenum GLError = glGetError();
	if (GLError != GL_NO_ERROR) {
	    gLogger.log(Loglevel::ERROR, "error while loading texture " + name + ": " + std::to_string((int)GLError));
    }

	gLogger.log(Loglevel::INFO, "texture " + name + " loaded", "Loader");

	return texture;
}

void Loader::deleteTexture(GLuint tex) {
	glDeleteTextures(1, &tex);
}



}}
