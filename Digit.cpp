#include "Digit.h"

Digit::Digit()
{
    DEBUG_PRINT("Digit Constructor");
    m_currentIndex = 0;

    void * address =  mmap(NULL, sizeof(double)*PIXEL_COUNT, 
                            PROT_READ|PROT_WRITE, 
                            MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    m_picture = new(address) Array<double>(PIXEL_COUNT);

    address =  mmap(NULL, sizeof(double)*OUTPUT_RANGE, 
                            PROT_READ|PROT_WRITE, 
                            MAP_SHARED|MAP_ANONYMOUS, -1, 0);
    m_label = new(address) Array<double>(OUTPUT_RANGE);
}

Digit& Digit::operator=(const Digit &dig)
{
    //Array<double> temp = dig.getPicture(); // fix this - const'ness issue
    *m_picture = dig.getPicture();
    //temp = dig.getLabel();
    //m_label.swap(temp);
    //*m_label = dig.getLabel();
    *m_label = *dig.m_label;
    m_currentIndex = dig.m_currentIndex;
    return *this;
}

bool Digit::addPixel(const unsigned char pixel)
{
    DEBUG_PRINT("Adding Pixel, current index is " << m_currentIndex);
    if (m_currentIndex++ < PIXEL_COUNT) {
        m_picture->push_back((int) pixel / 255);
        return true;
    }else{
        return false;
    }
}

Array<double> Digit::getPicture() const { return *m_picture; }

Array<double> Digit::getLabel() const { return *m_label; }

void Digit::setLabel(const unsigned char label)
{
    unsigned i;
    for (i = 0; i < label; i++) {
        m_label->push_back(0);
    }
    m_label->push_back(1);
    for (unsigned j = 9; j > i; j--){
        m_label->push_back(0);
    }
}

void Digit::clean()
{
    m_currentIndex = 0;
    m_picture->clear();
    m_label->clear();
}