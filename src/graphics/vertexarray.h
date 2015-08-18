#pragma once

#include <GL/glew.h>
#include <vector>

#include "../maths/vec3.h"
<<<<<<< HEAD
#include "buffer.h"
=======
>>>>>>> 8e34ec082a25d14bae18f545736457dc871c3dda

namespace Glow {
 
    class VertexArray {
        private:
            GLuint id_;
<<<<<<< HEAD
            std::vector <Buffer*> buffers_;
        public:
            VertexArray();
            ~VertexArray();
            void addBuffer(Buffer *buffer, GLuint index);
            void bind() const;
            void unbind() const;
=======
        public:
            VertexArray();
            VertexArray(float vertices[]);
        
            GLuint getID();
>>>>>>> 8e34ec082a25d14bae18f545736457dc871c3dda
            
    };

}
