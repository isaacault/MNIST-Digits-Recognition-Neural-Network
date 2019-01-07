#include "NetManager.h"

NetManager::NetManager(SharedMem * shmem, const vector<unsigned> &topology) :
    m_myNetwork(topology)
{
    DEBUG_PRINT("NetManager Constructor");
    
    Array<double> * resultVals = new Array<double>(OUTPUT_RANGE);
    
    while(1) { // fix this
        usleep(500000);

        while(!shmem->consumed()) {
            DEBUG_PRINT("NetManager taking action");
            m_currentDigit = shmem->getDigit();
            shmem->setConsumed(true);
            DEBUG_PRINT("Feeding forward...");
            m_myNetwork.feedForward(m_currentDigit.getPicture());
            DEBUG_PRINT("Back propogating...");
            m_myNetwork.backProp(m_currentDigit.getLabel());
            DEBUG_PRINT("Getting results...");
            m_myNetwork.getResults(*resultVals);
            printOutput(m_currentDigit.getLabel(), *resultVals);
        }

        // DEBUG_PRINT("NetManager skipped action");
    }
}

void NetManager::printOutput(Array<double> label, Array<double> results)
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