#include "Digit.h"

Digit::Digit()
{
    DEBUG_PRINT("Digit Constructor");
    ready = false;
}


void Digit::pushBack(const unsigned char pixel)
{
    m_picture.push_back(pixel);
}

bool Digit::isReady()
{
    return ready;
}