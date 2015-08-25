#pragma once

#include <string>

namespace Glow {
//TODO: implement logging on an extra thread (with a logging queue)
//TODO: implement a log file

    enum Loglevel {
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    class Logger {
        public:
            Logger();
            void log(Loglevel level, std::string message);
            void log(Loglevel level, std::string message, std::string source);

        private:
            std::string getLevelString(Loglevel level);
            void printlog(Loglevel level, std::string log);
    };

    static Logger gLogger = Logger();


}
