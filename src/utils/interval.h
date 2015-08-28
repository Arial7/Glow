#pragma once

namespace Glow {namespace utils{

    struct Interval {
        Interval (long interval, void (*callback)(), int id) : interval_(interval),
            delay_(interval), callback_(callback), id_(id){};

        long interval_;
        long delay_;
        void (*callback_)();
        int id_;
    };

}}
