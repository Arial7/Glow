#pragma once

namespace Glow { namespace utils {

    struct Timeout {
        Timeout (long delay, unsigned int id) : delay_(delay), id_(id){};
        long delay_;
        unsigned int id_;
    };
}}
