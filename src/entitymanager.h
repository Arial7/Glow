#pragma once

#include <vector>

#include "component.h"

namespace Glow {

    class EntityManager {
        public:
            ~EntityManager();
            void buildEntity(std::vector<Component*> components);
            void addComponent(unsigned int entityID, Component *component);
            void deleteEntity(unsigned int entityID);
        private:
            std::vector<unsigned int> entities_;
            std::vector<Component*> components_;
            unsigned int currentID = 0;
    };

}
