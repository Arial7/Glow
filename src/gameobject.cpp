#include "gameobject.h"

namespace Glow {

    GameObject::GameObject(Component *input, Component *physics, 
            Component *graphics){
        input_ = input;
        physics_ = physics;
        graphics_ = graphics;
    }

    GameObject::~GameObject(){
        delete input_;
        delete physics_;
        delete graphics_;
    }

    void GameObject::update(){
        input_->update();
        physics_->update();
        graphics_->update();
    }

    void GameObject::setInputComponent(Component *component){
        input_ = component;
    }
    void GameObject::setPhysicsComponent(Component *component){
        physics_ = component;
    }
    void GameObject::setGraphicsComponent(Component *component){
        graphics_ = component;
    }
      
    

}
