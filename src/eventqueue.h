#pragma once

#include <vector>

namespace Glow {

    class EventQueue {
        private:
            void(* window_focus_event)(bool focused);
        public:
            EventQueue();
            ~EventQueue();
            void setWindowFocusHandler(const void& window_focus_event(bool focused));
            
        private: 
            friend class DisplayManager;       

    };

}
