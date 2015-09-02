#pragma once

namespace Glow { namespace utils {

    struct Timeout {
        Timeout (double delay, void (*callback)()) : delay_(delay), callback_(callback){};
        double delay_;
        void (*callback_)();
    };
}}
