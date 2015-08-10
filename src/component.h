#pragma once

namespace Glow {
    
    class Component {
        protected:
            unsigned int entityID_;
        public:
            Component() : entityID_(0){};
            virtual ~Component() = 0;
            virtual void update() = 0;
            void setEntityID(unsigned int entityID) {entityID_ = entityID;};
            unsigned int getEntityID() {return entityID_;};
    };

}
