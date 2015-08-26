#pragma once

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>

//TODO: maybe implement multiple windows (most games don't need that)

namespace Glow { namespace graphics {

    class DisplayManager {
        private:
            int width_ = 0;
            int height_ = 0;
            SDL_Window *window_ = NULL; //only one window supported for now
            SDL_GLContext context_ = NULL; //only one context supported for now
        public:
            ~DisplayManager();
            void createWindow(int width, int height, std::string title);
            void destroyWindow();
            void clearWindow() const;
            void swapWindow() const;
            void setWindowTitle(std::string title);

            //callback
            void window_resized(int width, int height);

            SDL_Window *getWindow();

        private:
            void initSDL(std::string title);
            void initGL();

    };

}}
