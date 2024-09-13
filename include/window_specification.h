#ifndef JUMI_JPOCKET_WINDOW_SPECIFICATION_H
#define JUMI_JPOCKET_WINDOW_SPECIFICATION_H

namespace JPocket
{

    struct window_specification
    {
        const char* title = "JPocket";
        int width = 160;
        int height = 144;
        float scalar = 4.0f;
        unsigned int flags = 0;
        bool vsync = true;

        window_specification();
    };

}

#endif
