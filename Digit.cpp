#include "Digit.h"

Digit::Digit()
{
    DEBUG_PRINT("Digit Constructor");
    m_currentIndex = 0;
}

Digit& Digit::operator=(const Digit &dig)
{
    m_picture.swap(dig.getPicture);
    m_currentIndex = dig.m_currentIndex;
}

bool Digit::addPixel(const unsigned char pixel)
{
    if (m_currentIndex < PIXEL_COUNT) {
        m_picture.push_back(pixel);
        return true;
    }else{
        return false;
    }
}

vector<unsigned char> Digit::getPicture() { return m_picture; }

void Digit::setLabel(const unsigned char label)
{
    m_currentIndex = label;
}

void Digit::clean()
{
    m_currentIndex = 0;
}