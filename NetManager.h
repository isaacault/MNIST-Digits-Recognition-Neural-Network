#ifndef NETMANAGER_H
#define NETMANAGER_H

/******************************************************************************
 * NetManager is used to manage the Net. This is essentially the main function
 * for the parent process. It handles reading from the shared memory and
 * calling the appropriate functions from Net with the appropriate arguments.
******************************************************************************/

#include "Net.h"
#include "Digit.h"
#include "defs.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "SharedMem.h"
#include <unistd.h>
#include "Array.h"

using namespace std;

class NetManager
{
    public:
        NetManager(SharedMem * shmem, const vector<unsigned> &topology);
        void printOutput(Array<double> label, Array<double> results);

    private:
        Net m_myNetwork;
        Array<Digit> m_currentDigit;
        int m_successCount;
        int m_failureCount;

};

#endif