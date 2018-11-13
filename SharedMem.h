#ifndef SHAREDMEM_H
#define SHAREDMEM_H

#include <semaphore.h>
#include "Digit.h"
#include "defs.h"

class SharedMem
{
    public:
        SharedMem();
        void setNetworkPID(pid_t pid);
        void setParserPID(pid_t pid);
        void setDigit(Digit dig);
        pid_t getNetworkPID();
        pid_t getParserPID();
        Digit getDigit();
        bool consumed();
        void setConsumed(bool val);

    private:
        bool m_finishedRead;
        pid_t m_network;
        pid_t m_parser;
        Digit m_digit;
        sem_t m_sem;
        bool m_consumed;
};

#endif