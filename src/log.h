#ifndef LOG_H
#define LOG_H


//TODO: implement logging on an extra thread

enum LogLevel {
    INFO,
    WARN,
    ERROR,
    FATAL
};

void log(LogLevel level, const char *message);
void log(LogLevel level, const char *message, const char *source);
void log(LogLevel level, const char *message, const char *source,
        int line);

#endif
