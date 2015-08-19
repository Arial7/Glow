#pragma once

#include <GL/glew.h>
#include <vector>

#include "../maths/vec3.h"
#include "buffer.h"

namespace Glow {
 
    class VertexArray {
        private:
            GLuint id_;
            std::vector <Buffer*> buffers_;
        public:
            VertexArray();
            ~VertexArray();
            void addBuffer(Buffer *buffer, GLuint index);
            void bind() const;
            void unbind() const;
    };

}
