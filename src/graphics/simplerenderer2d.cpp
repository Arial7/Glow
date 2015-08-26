#include "simplerenderer2d.h"

namespace Glow { namespace graphics {

SimpleRenderer2D::SimpleRenderer2D(){

}

SimpleRenderer2D::~SimpleRenderer2D(){

}

void SimpleRenderer2D::init(){

}

void SimpleRenderer2D::submit(Renderable2D* renderable){
    drawables_.emplace_back(renderable);
}

void SimpleRenderer2D::flush(){

}

}}
