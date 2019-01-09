#include "NetManager.h"

NetManager::NetManager(SharedMem * shmem, const vector<unsigned> &topology) :
    m_myNetwork(topology), m_currentDigit(Array<Digit>(BATCH_SIZE))
{
    DEBUG_PRINT("NetManager Constructor");
    
    m_successCount = 0;
    m_failureCount = 0;

    //m_currentDigit = Array<Digit>(BATCH_SIZE);
    Array<double> * resultVals = new Array<double>(OUTPUT_RANGE);
    
    while(1) { // fix this

        while(m_currentDigit.size() < BATCH_SIZE){
            while(!shmem->consumed()){
                m_currentDigit.push_back(shmem->getDigit());
                shmem->setConsumed(true);
            }
        }

        unsigned iteration, digitIndex;
        for(iteration = 0; iteration < NUM_ITERATIONS; iteration++){
            for(digitIndex = 0; digitIndex < BATCH_SIZE; digitIndex++){
                DEBUG_PRINT("NetManager taking action");
                DEBUG_PRINT("Feeding forward...");
                m_myNetwork.feedForward(m_currentDigit[digitIndex].getPicture());
                DEBUG_PRINT("Back propogating...");
                m_myNetwork.backProp(m_currentDigit[digitIndex].getLabel());
                DEBUG_PRINT("Getting results...");
                m_myNetwork.getResults(*resultVals);
                printOutput(m_currentDigit[digitIndex].getLabel(), *resultVals);
            }
        }

        m_currentDigit.clear();
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