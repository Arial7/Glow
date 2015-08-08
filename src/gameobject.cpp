#include "gameobject.h"

namespace Glow {

GameObject::GameObject(){
	width = 32;
	height = 32;
}

GameObject::GameObject(Vec3 position, float width, float height){
	this->width = width;
	this->height = height;
}


float GameObject::getWidth(){
	return width;
}

float GameObject::getHeight(){
	return height;
}

GLuint GameObject::getTexture() {
	return texture;
}

void GameObject::setWidth(float width){
	this->width = width;
}

void GameObject::setHeight(float height){
	this->height = height;
}

void GameObject::setTexture(GLuint texture) {
	this->texture = texture;
}

}
