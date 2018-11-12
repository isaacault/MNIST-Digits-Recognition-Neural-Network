#include "defs.h"
#include "NetManager.h"
#include "Parser.h"
#include "SharedMem.h"
#include <unistd.h>
#include <iostream>
#include <sys/mman.h>
#include <string.h>

int main(int argc, char * argv[])
{
    
    vector<unsigned> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    //Net myNet(topology);
    /*
    vector<double> inputVals;
    myNet.feedForward(inputVals);

    vector<double> targetVals;
    myNet.backProp(targetVals);

    vector<double> resultVals;
    myNet.getResults(resultVals);
    */
    SharedMem * shmem = (SharedMem *) mmap(NULL, (size_t) 800, 
                                    PROT_READ|PROT_WRITE, 
                                    MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if (shmem == MAP_FAILED) {
        cerr << "Map Failed" << endl;
        abort();
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child Process
        DEBUG_PRINT("Child Process");
        shmem->setParserPID(getpid());

        // Call parser->digit
        Parser myParser(MNIST_DATA_DIRECTORY);
        
    }else if (pid > 0) {
        // Parent process
        DEBUG_PRINT("Parent Process");
        shmem->setNetworkPID(getpid());

        NetManager myManager(topology);
    }else {
        // fork failed
        cerr << "Fork Failed" << endl;
        return -1;
    }


}