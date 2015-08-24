#include "log.h"

#include <iostream>

namespace Glow {

Log& Log::logger(){
    static Log *instance_ = new Log();
    return instance_;
}

    void Log::log(Loglevel level, std::string message){
        printlog(level, message);
    }

    void Log::log(Loglevel level, std::string message, std::string source){
        std::string logmessage("[" + source + "]" + message);
        printlog(level, logmessage);
    }

    void Log::printlog(Loglevel level, std::string log){
        #ifdef GLOW_DEBUG
            #ifdef GLOW_DEBUG_VERBOSE
                if level == Loglevel::INFO {
                    std::cout << getLevelString(level) << log << std::endl;
                }
            #endif

            if level == Loglevel::WARN || level == Loglevel::ERROR  ||
                level == Loglevel::FATAL{
                std::cerr << getLevelString(level) << log << std::endl;
            }
        #endif
        #ifdef GLOW_DEBUG_ABORT_ON_FATAL
            if level == Loglevel::FATAL {
                abort();
            }
        #endif
    }

    std::string Log::getLevelString(Loglevel level){
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

    void Log::destroy(){
        delete instance_;
    }

}
