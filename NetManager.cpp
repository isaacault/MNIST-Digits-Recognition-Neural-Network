#include "NetManager.h"

NetManager::NetManager(const vector<unsigned> &topology) :
    m_myNetwork(topology)
{
    cout << "hello from NetManager!" << endl;
}