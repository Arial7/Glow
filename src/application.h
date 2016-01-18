/* -*- C++ -*- */

#pragma once

#include "glow.h"

#include "utils/log.h"


namespace glow {

    class Application {
    public:
        virtual void Start();
        virtual void End();
    private:
        Engine* engine;
    };


}
