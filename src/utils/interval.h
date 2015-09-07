#pragma once

namespace Glow { namespace utils{


    //NOTE: The delay is a double mesaured in seconds, so 0.75 would be 750 millseconds

    struct Interval {
        Interval (double interval, void (*callback)(), int id) : interval_(interval),
            delay_(interval), callback_(callback), id_(id){};

        double interval_;
        double delay_;
        void (*callback_)();
        int id_;
    };

}}
