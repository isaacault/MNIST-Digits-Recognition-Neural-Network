#ifndef PARSER_H
#define PARSER_H

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
        unsigned char endianSwap(unsigned char c);
        string m_MNISTDataDirectory;
        Digit m_digit;
};


#endif