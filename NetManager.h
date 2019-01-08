#ifndef NETMANAGER_H
#define NETMANAGER_H

#include "Net.h"
#include "Digit.h"
#include "defs.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "SharedMem.h"
#include <unistd.h>

using namespace std;

class NetManager
{
    public:
        NetManager(SharedMem * shmem, const vector<unsigned> &topology);
        void printOutput(Array<double> label, Array<double> results);

    private:
        Net m_myNetwork;
        Digit m_currentDigit;
        int m_successCount;
        int m_failureCount;

};

#endif