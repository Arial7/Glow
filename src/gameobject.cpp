#include "gameobject.h"

namespace Glow {
#ifdef GLOW_PRESET_2D
    GameObject::GameObject(Vec2 position, Component *input, Component *physics, 
            Component *graphics){
        position_ = position;
        input_ = input;
        physics_ = physics;
        graphics_ = graphics;
    }
#elif defined GLOW_PRESET_3D
    GameObject::GameObject(Vec3 position, Component *input, Component *physics,
            Component *graphics){
        position_ = position;
        input_ = input;
        physics_ = physics;
        graphics_ = graphics;
    }
    
#endif
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
