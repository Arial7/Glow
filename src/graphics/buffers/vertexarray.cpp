#include "vertexarray.h"

#include <string>

#include "../../utils/log.h"

namespace Glow { namespace graphics {

    using namespace utils;

    VertexArray::VertexArray(){
        glGenVertexArrays(1, &id_);
    }

    VertexArray::~VertexArray(){
        int count = 0;
        for (Buffer* buffer : buffers_){
            if(buffer != NULL){
                delete buffer;
                buffers_.erase(buffers_.begin());
                count++;
            }
        }
        gLogger.log(Loglevel::INFO, std::string(std::to_string(count) + " buffers deleted"));
        glDeleteVertexArrays(1, &id_);
    }

    void VertexArray::addBuffer(Buffer *buffer, GLuint index){
        bind();
        buffer->bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getComponents(), GL_FLOAT, GL_FALSE, 0, 0);

        buffer->unbind();
        unbind();

        buffers_.emplace_back(buffer);
    }

    void VertexArray::bind() const {
        glBindVertexArray(id_);
    }

    void VertexArray::unbind() const {
        glBindVertexArray(0);
    }


}}
