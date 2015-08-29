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
                        position.x, position.y, position.z,
                        position.x, position.y + size.y, position.z,
                        position.x + size.x, position.y + size.y, position.z,
                        position.x + size.x, position.y, position.z
                    };

                    vbo_ = new Buffer(vertices, 4 * 3, 3);

                    vao_->addBuffer(vbo_, 0);

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
