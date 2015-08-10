#include "entitymanager.h"
#include <algorithm>

namespace Glow {
    
    EntityManager::~EntityManager(){
        for (Component *component : components_) {
            delete component;
        }
    }

    void EntityManager::buildEntity(std::vector<Component*> components){
        entities_.emplace_back(++currentID);
        for (Component *component : components){
            component->setEntityID(currentID);
            components_.emplace_back(component);
        }    
    }

    void EntityManager::addComponent(unsigned int entityID, Component *component) {
        component->setEntityID(entityID);
        components_.emplace_back(component);
    }

    void EntityManager::deleteEntity(unsigned int entityID){
        for (Component *component : components_) {
            if (component->getEntityID() == entityID) {
                delete component;
            }
        }
        
        std::vector<unsigned int>::iterator position = std::find(entities_.begin(),
               entities_.end(), entityID);
        if (position != entities_.end()){
            entities_.erase(position);
        } 

    }

}
