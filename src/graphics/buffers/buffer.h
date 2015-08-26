#pragma once

#include <GL/glew.h>

namespace Glow { namespace graphics {

    class Buffer {
        private:
            GLuint id_;
            GLuint components_;

        public:
            Buffer(GLfloat *data, GLsizei count, GLuint components);
            ~Buffer();
            void bind() const;
            void unbind() const;
            GLuint getComponents() const;

    };
}}
