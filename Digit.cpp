#include "Digit.h"

Digit::Digit()
{

}


void Digit::pushBack(const unsigned char pixel)
{
    m_picture.push_back(pixel);
}

bool Digit::isReady()
{
    return ready;
}