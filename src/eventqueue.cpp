#include "eventqueue.h"

#include <SDL2/SDL.h>

namespace Glow {
    EventQueue::EventQueue(){

    }

    EventQueue::~EventQueue(){
        //delete function pointers
    }

    void EventQueue::pushEvent(GlowEvent& event){
        currentEvents_.emplace_back(event);
    }
    
    GlowEvent EventQueue::popEvent(){
        if (!currentEvents_.empty()){
            GlowEvent tempEvent(currentEvents_.front());
            currentEvents_.erase(currentEvents_.begin());
            return tempEvent;
        }
        else {
            GlowEvent tempEvent(GLOW_EVENT_NONE);
            return tempEvent;
        }
    }
   
    void EventQueue::pollEvents(){
        SDL_Event event;
        while (SDL_PollEvent (&event)){
            switch (event.type) {
                case SDL_QUIT:
                    currentEvents_.emplace_back(GlowEvent(GLOW_EVENT_ENGINE_SHOULD_EXIT));
                    break;
                case SDL_WINDOWEVENT:
                    switch(event.window.event){
                        case SDL_WINDOWEVENT_RESIZED:
                            //TODO: add new window size
                            currentEvents_.emplace_back(GlowEvent(GLOW_EVENT_WINDOW_RESIZED));
                    }
                    break;
                
            }
        }


    }

}
