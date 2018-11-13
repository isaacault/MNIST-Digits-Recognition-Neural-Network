#include "NetManager.h"

NetManager::NetManager(SharedMem * shmem, const vector<unsigned> &topology) :
    m_myNetwork(topology)
{
    DEBUG_PRINT("NetManager Constructor");
    
    vector<unsigned char> resultVals;
    
    while(!shmem->consumed()) {
        m_currentDigit = shmem->getDigit();
        shmem->setConsumed(true);
        m_myNetwork.feedForward(m_currentDigit.getPicture());
        m_myNetwork.backProp(m_currentDigit.getLabel());
        m_myNetwork.getResults(resultVals);
        printOutput(m_currentDigit.getLabel(), resultVals);
    }

}