#ifndef PARSER_H
#define PARSER_H

/******************************************************************************
 * Parser is essentially the main function for the child process. Parser is
 * used to read the MNIST digit data, flip the endianness, and write it to 
 * shared memory for NetManager.
******************************************************************************/

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "defs.h"
#include "Digit.h"
#include "SharedMem.h"
#include <unistd.h>

using namespace std;

class Parser
{
    public:
        Parser(SharedMem * shmem, vector<string> file, const string path="MNIST/");
        bool fillQueue();

    private:
        void traversePastHeader(FILE * fp);
        unsigned int endianSwap(unsigned int c);
        string m_MNISTDataDirectory;
        Digit m_digit;
};


#endif