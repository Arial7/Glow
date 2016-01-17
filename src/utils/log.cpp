#include "log.h"

#include <iostream>

namespace glow{ namespace utils {

    void Log(Level level, std::string message) {
        std::string levelString;

        switch (level) {
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
        std::cout << "[ENGINE]" + levelString + message << std::endl;
    }

    void Log(Level level, char* message) {
        std::string levelString;

        switch (level) {
            case INFO:
                levelString = "[INFO]";
            case WARN:
                levelString = "[WARN]";
            case ERROR:
                levelString = "[ERROR]";
            case FATAL:
                levelString = "[FATAL]";
        }
        std::cout << "[ENGINE]" + levelString + message << std::endl;
    }

}}
