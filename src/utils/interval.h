#pragma once

namespace Glow {namespace utils{

    struct Interval {
        Interval (long interval, void (*callback)()) : interval_(interval),
            delay_(interval), callback_(callback){};

        const long interval_;
        long delay_;
        void (*callback_)();
    };

}}
