#pragma once

//Special Events
#define GLOW_EVENT_NONE                     0

//Main Engine Events
#define GLOW_EVENT_ENGINE_FINISHED_INIT     11

//Window Events
#define GLOW_EVENT_WINDOW_CLOSE_REQUESTED   101
#define GLOW_EVENT_WINDOW_RESIZED           102
#define GLOW_EVENT_WINDOW_FOCUSED           103
#define GLOW_EVENT_WINDOW_FOCUS_LOST        104
#define GLOW_EVENT_WINDOW_MINIMIZED         105
//#define GLOW_EVENT_WINDOW_MAXIMIZED         106


namespace Glow {

    class GlowEvent {
        public:
            unsigned int type;    
            long data1;
            long data2;        

        public:
            GlowEvent(unsigned int _type){type = _type;};
            GlowEvent(unsigned int _type, long _data1){type = _type; data1 = _data1;};
            GlowEvent(unsigned int _type, long _data1, long _data2){type = _type; data1 = _data1;
                data2 = _data2;};            
            GlowEvent(const GlowEvent& copy){type = copy.type; data1 = copy.data1;
                data2 = copy.data2;};

    };

}
