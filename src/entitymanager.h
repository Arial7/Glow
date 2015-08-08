#pragma once

#include <vector>

#include "component.h"
#include "transformcomponent.h"
#include "quadcomponent.h"

namespace Glow {

    class EntityManager {
        public:
            void buildEntity(std::vector<Component*> components);
            void addComponent(int entityID, Component* component);
            void deleteEntity(int entityID);
        private:
            std::vector<int>entities_;
            std::vector<Component*>components_;
            int lastID = 0;
    };

}
