#include "Parser.h"

Parser::Parser(const string path)
{
    if (!path.empty()){
        m_mnist_folder_path = path;
    }
}