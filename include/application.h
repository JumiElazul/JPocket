#ifndef JUMI_JPOCKET_APPLICATION_H
#define JUMI_JPOCKET_APPLICATION_H
#include "window_handler.h"
#include "gui_handler.h"
#include "window_specification.h"

namespace JPocket
{

    class application
    {
    public:
        application();
        int run();

    private:
        window_specification _window_specification;
        window_handler _window_handler;
        gui_handler _gui;
        bool _running;

        void run_event_loop();
        void poll_gui_signals();
    };

}

#endif
