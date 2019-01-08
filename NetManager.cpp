#include "NetManager.h"

NetManager::NetManager(SharedMem * shmem, const vector<unsigned> &topology) :
    m_myNetwork(topology)
{
    DEBUG_PRINT("NetManager Constructor");
    
    m_successCount = 0;
    m_failureCount = 0;

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
    double labelPos=0, resultPos=0, tempMax=-1;
    for (unsigned i = 0; i < label.size(); i++) {
        // cout << "Label[" << i << "]: " << label[i] << " | " << "tempMax: " << tempMax << endl;
        if (label[i] > tempMax) {
            tempMax = label[i];
            labelPos=i;
            // cout << "Update labelPos to " << i << endl;
        }
    }
    tempMax = -1;
    for (unsigned i = 0; i < results.size(); i++) {
        // cout << "Results[" << i << "]: " << results[i] << " | " << "tempMax: " << tempMax << endl;
        if (results[i] > tempMax) {
            tempMax = results[i];
            resultPos=i;
            // cout << "Update resultPos to " << i << endl;
        }
    }

    cout << endl;
    cout << "ITERATION " << m_successCount + m_failureCount << endl;
    cout << "Digit : " << labelPos << endl;
    cout << "Read  : " << resultPos << endl;
    //cout << ((resultPos == labelPos) ? "SUCCESS" : "FAILURE") << endl;
    if (resultPos == labelPos){
        cout << "SUCCESS" << endl;
        m_successCount++; 
    }else{
        cout << "FAILURE" << endl;
        m_failureCount++;
    }
    cout << "Current success count: " << m_successCount << endl;
    //cout << m_myNetwork << endl;
}