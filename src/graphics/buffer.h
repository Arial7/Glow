#pragma once

#include <GL/glew.h>

namespace Glow {
    
    class Buffer {
        private:
            GLuint id_;
            Gluint components_;

        public:
            Buffer(GLfloat *data, GLsizei count, GLuint components);
            void bind() const;
            void unbind() const;
            GLuint getCompontents() const;

    };
}

