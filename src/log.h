#pragma once

#include <string>

namespace Glow {
//TODO: implement logging on an extra thread (with a logging queue)

enum LogLevel {
    INFO,
    WARN,
    ERROR,
    FATAL
};

//const char *
void log(LogLevel level, const char *message);
void log(LogLevel level, const char *message, const char *source);
void log(LogLevel level, const char *message, const char *source,
        int line);
}
