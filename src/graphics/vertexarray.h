#pragma once

#include <GL/glew.h>
#include <vector>
#include "../maths/vec3.h"

namespace Glow {
 
    class VertexArray {
        private:
            GLuint id_;
        public:
            VertexArray();
            VertexArray(float vertices[]);
        
            GLuint getID();
            
    };

}
