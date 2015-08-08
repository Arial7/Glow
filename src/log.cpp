#include <iostream>
#include <time.h>
#include "log.h"

namespace Glow {

void log(LogLevel level, const char *message){
    const char *levelString;
    switch(level){
        case INFO:
            levelString = "[INFO]";
            break;
        case WARN:
            levelString = "[WARN]";
            break;
        case ERROR:
            levelString = "[ERROR]";
            break;
        case FATAL:
            levelString = "[FATAL]";
            break;
    }
    #ifndef NDEBUG
    std::cout << levelString << message << std::endl; 
    #endif
}

void log(LogLevel level, const char *message, const char *source){
    const char *levelString;
    switch(level){
        case INFO:
            levelString = "[INFO]";
            break;
        case WARN:
            levelString = "[WARN]";
            break;
        case ERROR:
            levelString = "[ERROR]";
            break;
        case FATAL:
            levelString = "[FATAL]";
            break;
    }
    #ifndef NDEBUG
    std::cout << levelString << "[" << source << "]" << message << std::endl; 
    #endif
}
void log(LogLevel level, const char *message, const char *source, int line){
    const char *levelString;
    switch(level){
        case INFO:
            levelString = "[INFO]";
            break;
        case WARN:
            levelString = "[WARN]";
            break;
        case ERROR:
            levelString = "[ERROR]";
            break;
        case FATAL:
            levelString = "[FATAL]";
            break;
    }
    #ifndef NDEBUG
    std::cout << levelString << "[" << source << "]" << message 
        << "(on line: " << line << ")" << std::endl; 
    #endif
}

}
