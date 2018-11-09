#include "Parser.h"

Parser::Parser(const string path)
{
    DEBUG_PRINT( "Parser Constructer. Path " << path );

    if (!path.empty()){
        m_MNISTDataDirectory = path;
    }

}