#pragma once


#include "shader.h"

#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"

#include "../maths/maths.h"

namespace Glow { namespace graphics {

    using namespace maths;

    class Renderable2D {
        private:
            vec3 position_;
            Buffer* vbo_;
            VertexArray* vao_;
            IndexBuffer ibo_;
            Shader* shader_;
        public:
            Renderable2D(vec3 position, vec2 size, Shader* shader) :
                position_(position), shader_(shader){
                    vao_ = new VertexArray();

                    GLushort indices[] = {0, 1, 2, 2, 3, 0};
                    ibo_ = IndexBuffer(indices, 6);

                    GLfloat vertices[] = {
                        0, 0, 0,
                        0, size.y, 0,
                        size.x, size.y, 0,
                        size.x, 0, 0
                    };

                    vbo_ = new Buffer(vertices, 4 * 3, 3);

                    vao_->addBuffer(vbo_, 0);

                    //shader_->glVertexAttribPointer(SHADER_ATTRIB_POSITION, )


                };
            ~Renderable2D(){
                delete vbo_;
                //delete vao_;
            }

            void setPosition(vec3 position){position_ = position;};

            vec3 getPosition(){return position_;};
            VertexArray* getVAO(){return vao_;};
            IndexBuffer getIBO(){return ibo_;};
            Shader* getShader(){return shader_;};

    };

}}
