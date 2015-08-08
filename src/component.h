#pragma once

namespace Glow {
    
    class Component {
        public:
            Component(int entityID = -1) : entityID_(entityID) {};
            virtual ~Component() = 0;
            virtual void update() = 0;
        protected:
            int entityID_;
    };

}
