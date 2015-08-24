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

    class Log {
        public:
            static Log& logger();
            void log(Loglevel level, std::string message);
            void log(Loglevel level, std::string message, std::string source);

            void destroy();
        private:
            Log(){};

            std::string getLevelString(Loglevel level);
            void printlog(Loglevel level, std::string log);
    };

}
