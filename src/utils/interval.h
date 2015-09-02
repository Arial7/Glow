#pragma once

namespace Glow {namespace utils{

    struct Interval {
        Interval (double interval, void (*callback)(), int id) : interval_(interval),
            delay_(interval), callback_(callback), id_(id){};

        double interval_;
        double delay_;
        void (*callback_)();
        int id_;
    };

}}
