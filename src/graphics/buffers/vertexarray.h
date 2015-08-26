#pragma once

#include <GL/glew.h>
#include <vector>

#include "buffer.h"

#include "../../maths/vec3.h"

namespace Glow { namespace graphics {

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

}}
