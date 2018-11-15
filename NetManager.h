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
        NetManager(SharedMem & shmem, const vector<unsigned> &topology);
        void printOutput(vector<double> label, vector<double> results);

    private:
        Net m_myNetwork;
        Digit m_currentDigit;

};

#endif