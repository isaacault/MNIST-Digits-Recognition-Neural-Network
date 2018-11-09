#include "NetManager.h"

NetManager::NetManager(const vector<unsigned> &topology) :
    m_myNetwork(topology)
{
    DEBUG_PRINT("NetManager Constructor");
}