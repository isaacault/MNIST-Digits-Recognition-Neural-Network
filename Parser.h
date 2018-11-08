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
        Parser(const string path);
        bool fill_queue();

    private:
        string m_mnist_folder_path;
        vector<string> readWord();

};


#endif