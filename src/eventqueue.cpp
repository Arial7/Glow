#include "eventqueue.h"

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
   


}
