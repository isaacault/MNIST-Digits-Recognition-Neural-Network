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
    vector<string> filenames;
    /** this should be done differently (from defs or argv?) */
    filenames.push_back("train-images-idx3-ubyte");
    filenames.push_back("train-labels-idx1-ubyte");
    filenames.push_back("t10k-images-idx3-ubyte");
    filenames.push_back("t10k-labels-idx1-ubyte");
    
    vector<unsigned> topology;
    topology.push_back(PIXEL_COUNT);
    topology.push_back(16);
    topology.push_back(16);
    topology.push_back(10);
    //Net myNet(topology);
    /*
    vector<double> inputVals;
    myNet.feedForward(inputVals);

    vector<double> targetVals;
    myNet.backProp(targetVals);

    vector<double> resultVals;
    myNet.getResults(resultVals);
    */
    void * address =  mmap(NULL, (size_t) 2700, 
                                    PROT_READ|PROT_WRITE, 
                                    MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if (address == MAP_FAILED) {
        cerr << "Map Failed" << endl;
        abort();
    }

    SharedMem * shmem = new(address) SharedMem();

    pid_t pid = fork();

    if (pid == 0) {
        // Child Process
        DEBUG_PRINT("Child Process");
        shmem->setParserPID(getpid());

        // Call parser->digit
        Parser myParser(shmem, filenames, MNIST_DATA_DIRECTORY);
        
    }else if (pid > 0) {
        // Parent process
        DEBUG_PRINT("Parent Process");
        shmem->setNetworkPID(getpid());

        NetManager myManager(shmem, topology);
    }else {
        // fork failed
        cerr << "Fork Failed" << endl;
        return -1;
    }


}