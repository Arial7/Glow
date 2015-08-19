#pragma once

#include <GL/glew.h>

namespace Glow {
    
    class IndexBuffer {
        private:
            GLuint id_;
            GLuint count_;
        public:
            IndexBuffer(GLushort *data, GLuint count);
            void bind() const;
            void unbind() const;
            GLuint getCount() const;

    };


}
