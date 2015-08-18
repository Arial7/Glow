#pragma once

namespace Glow {
    
    class Component {
        public:
            virtual ~Component(){};
            virtual void update() = 0;
    };

}