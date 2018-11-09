#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

class Parser
{
    public:
        Parser(const string path="MNIST/");
        bool fillQueue();

    private:
        string m_MNISTDataDirectory;
        vector<string> readWord();

};


#endif