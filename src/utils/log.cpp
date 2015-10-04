#include "log.h"

#include <iostream>

namespace Glow { namespace utils {

    Logger::Logger(){
    }

    void Logger::log(Loglevel level, std::string message){
        printlog(level, message);
    }

    void Logger::log(Loglevel level, std::string message, std::string source){
        std::string logmessage("[" + source + "]" + message);
        printlog(level, logmessage);
    }

    void Logger::printlog(Loglevel level, std::string log){
        #ifdef GLOW_DEBUG
            if (level == Loglevel::INFO) {
                std::cout << getLevelString(level) << log << std::endl;
            }
            else if (level == Loglevel::WARN || level == Loglevel::ERROR  ||
                level == Loglevel::FATAL) {
                std::cerr << getLevelString(level) << log << std::endl;
            }
        #endif
        #ifndef GLOW_N_ABORT_ON_FATAL
            if (level == Loglevel::FATAL) {
                abort();
            }
        #endif
    }

    std::string Logger::getLevelString(Loglevel level){
        std::string levelString;
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
        return levelString;
    }

}}
