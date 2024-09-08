#ifndef JUMI_JPOCKET_CPU_H
#define JUMI_JPOCKET_CPU_H
#include "typedefs.h"

namespace JPocket
{

    class cpu
    {
    public:

        cpu();

    private:
        BYTE _memory[0x2000];
    };

}

#endif
