#include "defs.h"
#include "NetManager.h"
#include "Parser.h"
#include <unistd.h>
#include <iostream>

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

    pid_t pid = fork();

    if (pid == 0) {
        cout << "child" << endl;
        // Child Process
        // Call parser->digit
        Parser myParser(MNIST_DATA_DIRECTORY);
        
    }else if (pid > 0) {
        cout << "aye" << endl;
        // Parent process
        NetManager myManager(topology);
    }else {
        // fork failed
        return 1;
    }


}