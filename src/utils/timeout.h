#pragma once

namespace Glow { namespace utils {

    struct Timeout {
        Timeout (long delay, void (*callback)()) : delay_(delay), callback_(callback){};
        long delay_;
        void (*callback_)();
    };
}}
