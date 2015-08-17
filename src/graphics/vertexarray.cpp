#include "vertexarray.h"

namespace Glow {
 
    VertexArray::VertexArray(float vertices[]){
        glGenVertexArrays(1, &id_);
        glBindVertexArray(id_);
        glEnableVertexAttribArray(0);

        
    }


}
