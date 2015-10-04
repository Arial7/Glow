#pragma once

#include <GL/glew.h>
#include <vector>

#include "renderer2d.h"


#include "../renderable2d.h"

#include "../buffers/vertexarray.h"
#include "../buffers/indexbuffer.h"

namespace Glow { namespace graphics {

class SimpleRenderer2D : public Renderer2D {
    private:
        std::vector<Renderable2D*> drawables_;
        VertexArray* vao_;
        Buffer* vbo_;
        IndexBuffer ibo_;

    public:
        SimpleRenderer2D();
        ~SimpleRenderer2D();

        virtual void submit(Renderable2D* renderable);
        virtual void flush();
};

}}
