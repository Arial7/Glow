/* -*- C++ -*- */

#pragma once

#include <string>

namespace glow { namespace utils {

    enum Level {
        INFO,
        WARN,
        ERROR,
        FATAL
    };
    
    void Log(Level level, std::string message);
    void Log(Level level, char* message);





}}
