#include "Parser.h"

Parser::Parser(const string path)
{
    cout << "Hello from Parser!" << endl;
    cout << path << endl;
    if (!path.empty()){
        m_MNISTDataDirectory = path;
    }

}