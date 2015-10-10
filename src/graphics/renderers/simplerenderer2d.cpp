#include "simplerenderer2d.h"

#include <string>

#include "../shader.h"

#include "../buffers/indexbuffer.h"
#include "../buffers/vertexarray.h"

#include "../../maths/maths.h"

#include "../../utils/log.h"

namespace Glow { namespace graphics {

SimpleRenderer2D::SimpleRenderer2D(){
    vao_ = new VertexArray();
    GLushort indices[] = {0, 1, 2, 2, 3, 0};
    ibo_ = IndexBuffer(indices, 6);


}

SimpleRenderer2D::~SimpleRenderer2D(){

}

void SimpleRenderer2D::submit(Renderable2D* renderable){
    drawables_.emplace_back(renderable);
}

void SimpleRenderer2D::flush(){
    for (unsigned int i = 0; i < drawables_.size(); i++){
        Renderable2D* renderable = drawables_.at(i);
        renderable->getShader()->bind();

//        renderable->getShader()->setUniformMat4("modelview_matrix", maths:: );
        //renderable->getShader()->setUniformMat4("projection_matrix",
            //maths::mat4::orthographic(0, 1280, 0, 720, 1, -1));
        renderable->getShader()->setUniform3f("translation", renderable->getPosition());

        renderable->getVAO()->bind();
        renderable->getIBO().bind();
        glDrawElements(GL_TRIANGLES, renderable->getIBO().getCount(), GL_UNSIGNED_SHORT, 0);
        renderable->getIBO().unbind();
        renderable->getVAO()->unbind();
        renderable->getShader()->unbind();

        drawables_.erase(drawables_.begin() + i);
    }
}

}}
