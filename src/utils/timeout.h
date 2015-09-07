#pragma once

namespace Glow { namespace utils {

    //NOTE: The delay is a double mesaured in seconds, so 0.75 would be 750 millseconds

    struct Timeout {
        Timeout (double delay, void (*callback)()) : delay_(delay), callback_(callback){};
        double delay_;
        void (*callback_)();
    };
}}
