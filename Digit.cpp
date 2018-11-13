#include "Digit.h"

Digit::Digit()
{
    DEBUG_PRINT("Digit Constructor");
    m_currentIndex = 0;
}

Digit& Digit::operator=(const Digit &dig)
{
    vector<double> temp = dig.getPicture(); // fix this - const'ness issue
    m_picture.swap(temp);
    m_currentIndex = dig.m_currentIndex;
}

bool Digit::addPixel(const unsigned char pixel)
{
    DEBUG_PRINT("Adding Pixel, current index is " << m_currentIndex);
    if (m_currentIndex++ < PIXEL_COUNT) {
        m_picture.push_back((int) pixel / 255);
        return true;
    }else{
        return false;
    }
}

vector<double> Digit::getPicture() const { return m_picture; }

vector<double> Digit::getLabel() { return m_label; }

void Digit::setLabel(const unsigned char label)
{
    unsigned i;
    for (i = 1; i < label; i++) {
        m_label.push_back(0);
    }
    m_label.push_back(1);
    for (unsigned j = 10; j > i; j--){
        m_label.push_back(0);
    }
}

void Digit::clean()
{
    m_currentIndex = 0;
}