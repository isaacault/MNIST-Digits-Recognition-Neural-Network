#include "Digit.h"

Digit::Digit()
{
    DEBUG_PRINT("Digit Constructor");
    
}


void Digit::pushBack(const unsigned char pixel)
{
    m_picture.push_back(pixel);
}
