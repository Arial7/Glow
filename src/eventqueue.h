#pragma once

#include <vector>

#include "event.h"

namespace Glow {

    class EventQueue {
        private:
            std::vector<GlowEvent> currentEvents_;

        public:
            EventQueue();
            ~EventQueue();
            GlowEvent popEvent();
            void pushEvent(GlowEvent& event);
            void pollEvents();
            void registerHandler(void *handler);

    };

}
