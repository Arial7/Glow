#pragma once

#include <SDL2/SDL.h>

#include <GL/glew.h>

//TODO: maybe implement multiple windows (most games don't need that)

namespace Glow {

class DisplayManager {

    public:
        void createWindow(int _width, int _height, const char *_title);
        void destroyWindow();
        ~DisplayManager();
        
        SDL_Window *getWindow();
    private:
        int width = -1;
        int height = -1;
        SDL_Window *window = NULL; //Engine only supports one window
        SDL_GLContext context = NULL; //Engine only supports one context

        void initSDL(const char *_title);
        void initGL();

};

}
