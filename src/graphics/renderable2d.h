#pragma once

#include "shader.h"

#include "buffers/vertexarray.h"
#include "buffers/indexbuffer.h"

#include "../maths/vec3.h"
#include "../maths/vec2.h"

namespace Glow { namespace graphics {

    using namespace maths;

    class Renderable2D {
        private:
            vec3 position_;
            VertexArray vao_;
            IndexBuffer ibo_;
            Shader* shader_;
        public:
            Renderable2D(vec3 position, VertexArray vao, IndexBuffer ibo, Shader* shader) :
                position_(position), vao_(vao), ibo_(ibo), shader_(shader){};


            void setPosition(vec3 position){position_ = position;};

            vec3 getPosition(){return position_;};
            VertexArray getVAO(){return vao_;};
            IndexBuffer getIBO(){return ibo_;};
            Shader* getShader(){return shader_;};

    };

}}
