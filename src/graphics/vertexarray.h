#pragma once

#include <GL/glew.h>
#include <vector>
#include "../maths/vec3.h"
namespace Glow {
 
    class VertexArray {
        private:
            Gluint id_;
        public:
            VertexArray();
            VertexArray(std::vector<Vec3> vertices);
            VertexArray(float vertices[]);
        
            Gluint getID();
            
    };

}
