#include "vertexarray.h"

namespace Glow {
 
    VertexArray::VertexArray(){
        glGenVertexArrays(1, &id_);       
    }

    VertexArray::~VertexArray(){
        for (Buffer* buffer : buffers_){ 
            delete buffer;
        }

        glDeleteVertexArrays(1, &id_);
    }

    void VertexArray::addBuffer(Buffer *buffer, GLuint index){
        bind();
        buffer->bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getComponents(), GL_FLOAT, GL_FALSE, 0, 0);

        buffer->unbind();
        unbind();

        buffers.emplace_back(buffer);
    }

    void VertexArray::bind() const {
        glBindVertexArray(id_);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }


}
