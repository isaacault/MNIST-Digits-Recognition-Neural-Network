#ifndef NETMANAGER_H
#define NETMANAGER_H

#include "Net.h"
#include "Digit.h"
#include "defs.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include "SharedMem.h"

using namespace std;

class NetManager
{
    public:
        NetManager(SharedMem * shmem, const vector<unsigned> &topology);

    private:
        Net m_myNetwork;
        Digit m_currentDigit;

};

#endif