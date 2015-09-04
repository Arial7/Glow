#include "eventqueue.h"

#include <GLFW/glfw3.h>

namespace Glow {
    EventQueue::EventQueue(){

    }

    EventQueue::~EventQueue(){
        //delete function pointers
    }

    void EventQueue::setWindowFocusHandler(const void& window_focus_event(bool focused){
            this->window_focus_event = &window_focus_event;
     }

}
