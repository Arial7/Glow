#pragma once

#include <GL/glew.h>

namespace Glow { namespace graphics {

    class IndexBuffer {
        private:
            GLuint id_;
            GLuint count_;
        public:
            IndexBuffer(){};
            IndexBuffer(GLushort *data, GLuint count);
            void bind() const;
            void unbind() const;
            GLuint getCount() const;

    };


}}
