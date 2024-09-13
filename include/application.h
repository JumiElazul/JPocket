#ifndef JUMI_JPOCKET_APPLICATION_H
#define JUMI_JPOCKET_APPLICATION_H
#include "window_handler.h"

namespace JPocket
{

    class application
    {
    public:
        application();
        int run();

    private:
        window_handler _window_handler;
        bool _running;

        void run_event_loop();

    };

}

#endif
