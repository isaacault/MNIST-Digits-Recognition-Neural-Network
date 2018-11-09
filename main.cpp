#include "defs.h"
#include "NetManager.h"
#include "Parser.h"
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
    Digit * shDigit = (Digit *) mmap(NULL, (size_t) 800, 
                                PROT_READ|PROT_WRITE, 
                                MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    if (shDigit == MAP_FAILED) {
        cout << "Map Failed" << endl;
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child Process
        DEBUG_PRINT("Child Process");

        // Call parser->digit
        Parser myParser(MNIST_DATA_DIRECTORY);
        
    }else if (pid > 0) {
        DEBUG_PRINT("Parent Process");

        // Parent process
        NetManager myManager(topology);
    }else {
        // fork failed
        return 1;
    }


}