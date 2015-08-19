#pragma once

#include <SDL2/SDL.h>

#include <GL/glew.h>

//TODO: maybe implement multiple windows (most games don't need that)

namespace Glow {

class DisplayManager {
    private:
        int width_ = 0;
        int height_ = 0;
        SDL_Window *window_ = NULL; //only one window supported for now
        SDL_GLContext context_ = NULL; //only one context supported for now
    public:
        ~DisplayManager();
        void createWindow(int width, int height, const char *title);
        void destroyWindow();
        void clearWindow() const;
        void swapWindow() const;
        void window_resized(int width, int height);
        
        SDL_Window *getWindow();

    private:
        void initSDL(const char *title);
        void initGL();

};

}
