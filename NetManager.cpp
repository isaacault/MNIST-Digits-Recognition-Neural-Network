#include "NetManager.h"

NetManager::NetManager(SharedMem * shmem, const vector<unsigned> &topology) :
    m_myNetwork(topology)
{
    DEBUG_PRINT("NetManager Constructor");
    
    vector<double> resultVals;
    
    while(1) { // fix this
        usleep(50000);

        while(!shmem->consumed()) {
            DEBUG_PRINT("NetManager taking action");
            m_currentDigit = shmem->getDigit();
            shmem->setConsumed(true);
            m_myNetwork.feedForward((vector<double>) m_currentDigit.getPicture());
            m_myNetwork.backProp(m_currentDigit.getLabel());
            m_myNetwork.getResults(resultVals);
            printOutput(m_currentDigit.getLabel(), resultVals);
        }

        DEBUG_PRINT("NetManager skipped action");
    }
}

void NetManager::printOutput(vector<double> label, vector<double> results)
{
    int labelPos=0, resultPos=0, tempMax=0;
    for (unsigned i = 0; i < label.size(); i++) {
        if (label[i] > tempMax) {
            tempMax = label[i];
            labelPos=i;
        }
    }
    tempMax = 0;
    for (unsigned i = 0; i < results.size(); i++) {
        if (results[i] > tempMax) {
            tempMax = results[i];
            resultPos=i;
        }
    }

    cout << endl;
    cout << "Digit : " << labelPos << endl;
    cout << "Read  : " << resultPos << endl;
    cout << ((resultPos == labelPos) ? "SUCCESS" : "FAILURE") << endl;
}