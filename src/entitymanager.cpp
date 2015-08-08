#include "entitymanager.h"

namespace Glow {
    
    void EntityManager::buildEntity(std::vector<Component*> components){
        int entityID = lastID + 1;
        entities_.emplace_back(entityID);
        

        lastID++;
    }

}
