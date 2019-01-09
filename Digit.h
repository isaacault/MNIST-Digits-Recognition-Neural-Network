#ifndef DIGIT_H
#define DIGIT_H

/******************************************************************************
 * Digit is used to store a digit. That is, the 'picture' and the label of what
 * the digit written is.
******************************************************************************/

#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include "defs.h"
#include "Array.h"

using namespace std;

class Digit
{
    public:
        Digit();
        Digit& operator=(const Digit &dig);
        bool addPixel(const unsigned char pixel);
        Array<double> getPicture() const;
        void setLabel(const unsigned char label);
        Array<double> getLabel() const;
        void clean();

    private:
        int m_currentIndex; 
        Array<double> * m_picture;
        Array<double> * m_label;        
};


#endif