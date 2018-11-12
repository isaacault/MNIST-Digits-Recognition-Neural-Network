#include "Digit.h"

Digit::Digit() : index(0)
{
    DEBUG_PRINT("Digit Constructor");
    
}

Digit& Digit::operator=(const Digit &dig)
{
    memcpy(picture, dig.picture, sizeof(picture));
    index = dig.index;
}

bool Digit::addPixel(const unsigned char pixel)
{
    if (index < PIXEL_COUNT) {
        picture[index++] = pixel;
        return true;
    }else{
        return false;
    }
}


