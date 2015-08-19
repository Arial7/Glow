#include "buffer.h"

namespace Glow {
    
    Buffer::Buffer(GLfloat *data, GLsizei count, GLuint components){
        components_ = components;
        glGenBuffers(1, &id_);
        glBindBuffer(GL_ARRAY_BUFFER, id_);
        glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    }

    Buffer::~Buffer(){
        glDeleteBuffers(1, &id_);
    }

    void Buffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, id_);
    }

    void Buffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    GLuint Buffer::getComponents() const {
        return components_;
    }

}
