#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL_opengl.h>
#include "vec3.h"

class GameObject {
	public:
		GameObject();
		GameObject(Vec3 position, float width, float height);
		float getWidth(void);
		float getHeight(void);
		GLuint getTexture(void);
		void setWidth(float width);
		void setHeight(float height);
		void setTexture(GLuint texture);
	private:
		GLuint texture;
	protected:
		float width;
		float height;
};


#endif
